/*Creating a webserver Using ESP8266*/
#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include<DHT.h>
ESP8266WebServer server(80);
const char* ssid="YOUR_SSID";
const char* pwd="YOUR_PASSWORD";
String website; 
void websitecontent()
{
  website="<html><body>";
  website="HelloWorld";
  website+="</body></html>";
  server.send(200,"text/html",website);
}
void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid,pwd);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  WiFi.mode(WIFI_STA);
  Serial.println("Connected");
  Serial.println(WiFi.localIP());
  server.begin();
  server.on("/",websitecontent);
}
void loop()
{
  server.handleClient();
}
