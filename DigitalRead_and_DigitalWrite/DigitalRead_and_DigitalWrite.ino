int input_pin=D0;
int output_pin=D1;
int val;
void setup()
{
  pinMode(input_pin,INPUT);
  pinMode(output_pin,OUTPUT);
}
void loop()
{
  val=digitalRead(input_pin);
  digitalWrite(output_pin,val);
}
