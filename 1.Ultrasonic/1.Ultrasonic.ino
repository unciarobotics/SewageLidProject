#include <NewPing.h>
#include <MedianFilter.h>
#include <Wire.h>
#define TRIGGER_PIN  12  
#define ECHO_PIN     11  
#define MAX_DISTANCE 450 


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

MedianFilter filter(31,0);

void setup() {
  
  Serial.begin(115200); 

  
  
}

void loop() {
  
  delay(50);                     
  unsigned int o,uS = sonar.ping(); 
  filter.in(uS);
  o = filter.out();
  o = (o / US_ROUNDTRIP_CM);
  Serial.print(o); 
  Serial.println("cm");

  
}
