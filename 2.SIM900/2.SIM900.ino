#include <SoftwareSerial.h>
SoftwareSerial mySerial(6, 7); //10 to 5VT and 9 to 5VR

void setup()
{
  mySerial.begin(9600); // Setting the baud rate of GSM Module
  Serial.begin(9600);  // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  if (Serial.available()>0)
 switch(Serial.read())
 {
  case 's':
  SendMessage();
  break;
  case 'r':
  RecieveMessage();
  break;
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
  mySerial.println("Hello from sim900");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


 void RecieveMessage()
{ String x = "AT+CNMI=2,2,0,0,0";
  mySerial.println(x);
  delay(1000);
 }
 
