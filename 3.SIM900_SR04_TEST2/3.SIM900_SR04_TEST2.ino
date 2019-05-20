#include <SoftwareSerial.h>
SoftwareSerial mySerial(7, 6); //10 to 5VT and 9 to 5VR

#define trigPin 9
#define echoPin 10
int ctr=0;
int duration, distance;
void setup()
{
  mySerial.begin(9600); // Setting the baud rate of GSM Module
  Serial.begin(9600);  // Setting the baud rate of Serial Monitor (Arduino)
   pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(8,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(8,HIGH);
  digitalWrite(11,LOW);
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  pinMode(3,INPUT);
  delay(100);
}


void loop()
{ int GasSensor = analogRead(A6);
  int button = digitalRead(3);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance= (duration/2)/29.1;
  Serial.print("Distance: ");Serial.print(distance);
  Serial.print("cm");Serial.print("     Gas Level: ");Serial.println(GasSensor);
  
 if (distance<20&&ctr<=30)
 {ctr++;}
 if (distance<20&&ctr<30)
 {SendMessage();
  ctr=0;
  delay(10000);
  }
if (button==HIGH)
 {delay(100);
  SendMessageb();
  }

 if(GasSensor>=600)
 {SendMessagec();
  while(GasSensor>550)
  {
  GasSensor = analogRead(A6);
  Serial.println(GasSensor);
  delay(100);}
  }
 
 if (mySerial.available()>0)
 Serial.write(mySerial.read());
}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");  //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917018093520\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Warning! Water over detected. Water Level is below 30 cm");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void SendMessageb()
{
  mySerial.println("AT+CMGF=1");  //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917018093520\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Lid Opened");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void SendMessagec()
{
  mySerial.println("AT+CMGF=1");  //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917018093520\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("The level of Poisnous gas is rising above normal");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
 void RecieveMessage()
{ String x = "AT+CNMI=2,2,0,0,0";
  mySerial.println(x);
  delay(1000);
 }
 
