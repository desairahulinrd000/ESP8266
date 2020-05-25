/*Create a webserver which displayes the Temperature and Humidity
Using DHT11 Sensor*/
#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include<DHT.h>
DHT dht(0,DHT11);//D3 of ESP8266
float t,h;
ESP8266WebServer server(80);
const char* ssid="YOUR_SSID";
const char* pwd="YOUR_PASSWORD";

String website; 
void websitecontent()
{
  website="<html><body>";
  website+="Humidity:";
  website+=String(h);
  website+="</br>Temperature:";
  website+=String(t);
  website+="</body></html>";
  server.send(200,"text/html",website);
}
void setup()
{
  dht.begin();
  Serial.begin(115200);
  WiFi.begin(ssid,pwd);
  pinMode(0,INPUT);
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
  t=dht.readTemperature();
  h=dht.readHumidity();
  server.handleClient();
}
