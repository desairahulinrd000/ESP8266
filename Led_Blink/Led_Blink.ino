int led_pin=D0;
int sec=1000;
void setup()
{
  pinMode(led_pin,OUTPUT);
}
void loop()
{
  digitalWrite(led_pin,HIGH);
  delay(sec);
  digitalWrite(led_pin,LOW);
  delay(sec);
}
