#include <LiquidCrystal.h>
 #define Echo 9
 #define trigger 10
 #define buzz 10
 long duration;
 float distance;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

 void setup() {
   pinMode(trigger, OUTPUT);
   pinMode(Echo, INPUT);
   pinMode(7, OUTPUT);     //Buzzer
   pinMode(13, OUTPUT);    //yellow led
   pinMode(6, OUTPUT);     //orange led
   pinMode(8, OUTPUT);     //green led
   Serial.begin(9600);
   lcd.begin(16, 2);
 }

 void loop() {
   time_Measurement();
   distance = (float)duration * (0.0343) / 2;
   display_distance();
   
   if(distance<=80)
   {
     digitalWrite(7, HIGH);    //sound produced
   }
   else
   {
     digitalWrite(7, LOW);     //no sound
   }   
   if(distance<=50)
   {
     digitalWrite(6, HIGH);
     digitalWrite(13, LOW);
     digitalWrite(8, LOW);
   }
   else if(distance<=80&&distance>50)
   {
     digitalWrite(13, HIGH);
     digitalWrite(6, LOW);
     digitalWrite(8, LOW);
   }
   else if(distance>80&&distance<=120)
   {
     digitalWrite(8, HIGH);
     digitalWrite(13, LOW);
     digitalWrite(6, LOW);
   }
   else if(distance>100)
   {
     digitalWrite(6, LOW);
     digitalWrite(13, LOW);
     digitalWrite(8, LOW);
   }
 }

 void time_Measurement()
 {
   digitalWrite(trigger, LOW);
   delayMicroseconds(2);
   digitalWrite(trigger, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigger, LOW);
   duration = pulseIn(Echo, HIGH);
 }

 void display_distance()
 {
   lcd.setCursor(0, 0);
   Serial.print("Distance in cm: ");
   Serial.print(distance);
   Serial.println();
   lcd.print("Distance in cm: ");
   lcd.setCursor(6, 1);
   lcd.print(distance);
   delay(500);
 }
      
