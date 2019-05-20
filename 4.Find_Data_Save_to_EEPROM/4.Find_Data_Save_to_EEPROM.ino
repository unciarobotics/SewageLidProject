#include <EEPROM.h>
String x = "+AT CG, GC abcdefg The phone number +917018093520 first fetch it out";
int count = 5;
String Number;
void setup() {
Serial.begin(9600);

}

void loop() {
  int a = x.indexOf("+91")+3;
  int b = x.lastIndexOf(" first");
 
  String c = x.substring(a, b);
  int len = c.length();
  int phone[len] = {0};

 for(count=0;count<len;count++)
   {phone[count] = (x.substring(a+count,a+count+1)).toInt();
   EEPROM.write(count,phone[count]);
   }

Number = String(EEPROM.read(0));
for(int count2=1;count2<len;count2++)
   {Number = Number + String(EEPROM.read(count2));}
  
  Serial.println(Number);

  
/*  for(int p=0;a<len;a++)
  { phone= (x.substring(a+3+count,a+3+count+1)).toInt();
    delay(1000);
    Serial.println(phone);
    count++;}
  */
//for(int q=0;q<len;q++)
// {EEPROM.write(q,phone[q]);}


/*for(int r=0;r<len;r++)  
  {int temp = EEPROM.read(r)*multiple;
   readNumber = readNumber+temp;
   multiple/10;
   }*/

 // Serial.print(a);Serial.print("  ");Serial.print(b);Serial.print("  ");Serial.print(c);Serial.print("  ");Serial.println(len); 
}
