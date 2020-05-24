/*Automated Hand Sanitizer Dispensing using Arduino UNO
Items:
|-------------------------------------|
|      Name      |      Quantity      |
|-------------------------------------|
|Servo motor     |     1              |
|Arduino Uno     |     1              |
|PIR SENSOR      |     1              |
|Jumpers(M2F)    |     3              |
|Power Adaptor   |                    |
|6-12v,500mA     |     1              |
|-------------------------------------|


*/
#include <Servo.h>
const int dispense_time=1000,next_opt_time=5000;//Sanitizer dispense for 2 seconds and next operation ready time=5 seconds
const int pir_pin=12;//Connect PIR pin to pin 12 
const int servo_pin=11;//Connect Servo Control pin to pin 11 
int pir_value;
Servo myservo;
void setup()
{
  Serial.begin(9600);
  myservo.attach(servo_pin);
  myservo.write(0); 
  pinMode(pir_pin,OUTPUT);
}
void loop()
{
  pir_value=digitalRead(pir_pin);//Read The value from PIR Sensor which detect's for hand
  if(pir_value==1)
  {
    myservo.write(90);
    delay(dispense_time);
    myservo.write(0);
    delay(5000);
  } 
}
