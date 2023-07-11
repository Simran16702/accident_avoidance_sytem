//Push Button pulldown resistor(active high)

 int Headlight=5;
 int HighBeam=3;
 int BUTTON=2;
 int buttonRead;
 int LDR=A0;
 int LDRvalue;

void setup()
{
// initializing the serial communication
  Serial.begin(9600); 
  pinMode (3,OUTPUT);
  pinMode (5,OUTPUT);
  pinMode (BUTTON,INPUT);
}

void loop()
{
  LDRvalue = analogRead(A0); //read the sensor
  buttonRead= digitalRead(BUTTON);
  delay(1000);

if (buttonRead==0)  
 {
  Serial.print("Button State= ");
  Serial.println(buttonRead);
  digitalWrite(3,LOW);
 }

if (buttonRead==1)
 {
  Serial.print("Button State= ");
  Serial.println(buttonRead);
  digitalWrite(3,HIGH);
  Serial.println("High beam is turn on");
 }
if (LDRvalue<=300)
 {
  Serial.print("LDR Value= ");
  Serial.println(LDRvalue);
  digitalWrite(5,HIGH);
  Serial.println("It's dark outside. Headlight is turn on");
}
 if (LDRvalue>300)
 {
   Serial.print("LDR Value= ");
   Serial.println(LDRvalue);
   digitalWrite(5,LOW);
   Serial.println("It's bright outside. Headlight is turn off");
 }
}
