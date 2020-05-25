#include<ESP8266WiFi.h>
const char *ssid="view10";
const char *password="12312312333";
int LED=16;
WiFiServer server(80);
void setup()
{
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  server.begin();
}
void loop()
{
  WiFiClient client=server.available();
  if(!client)
  {
    return;
  }
  while(!client.available())
  {
    delay(1);
  }
  String input=client.readStringUntil('\r');
  client.flush();
  char state=LOW;
  if(input.indexOf("/LED=ON")!=-1)
  {
    digitalWrite(LED,HIGH);
    state=HIGH;
  }
  if(input.indexOf("/LED=OFF") != -1)
  {
    digitalWrite(LED, LOW);
    state=LOW;
  }
String HEAD="<!DOCTYPE html><html><head><title>LED Controll</title><style type=\"text/css\">*{margin:10px;background-color: black;color: white;font-family: cursive;text-align: center;}.button1{margin: 10px;width: 100px;height: 50px;background-color: green;color: black;font-weight: bold;}.button2{margin: 10px;width: 100px;height: 50px;background-color: red;color: black;font-weight: bold;}.button1:hover{background-color: yellow;}.button2:hover{background-color: yellow;}</style></head>";
String BODY1="<body><h1>LED CONTROLL</h1>";
String BODY2="<p>LED IS</p>";
String BODY3="<a class=\"link\" href=\"/LED=ON\"\"><button class=\"button1\">ON</button></a><a class=\"link\" href=\"/LED=OFF\"\"><button class=\"button2\">OFF</button></a></body></html>";
client.println(HEAD);
client.println(BODY1);
client.print(BODY2);
client.print("<h1>");
  if(state == HIGH)
  {
    client.println("ON");
  }
  else
  {
    client.println("OFF"); 
  }
 client.print("<\h1>");
client.println(BODY3);
  delay(1);
}
