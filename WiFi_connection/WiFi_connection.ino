#include<ESP8266WiFi.h>
const char* ssid="YOUR_SSID";
const char* pwd="YOUR_PASSWORD";
void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid,pwd);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected Successfully");
  Serial.print("IP:");
  Serial.println(WiFi.localIP());
}
void loop()
{
  
}
