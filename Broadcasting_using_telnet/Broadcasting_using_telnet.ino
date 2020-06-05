#include<ESP8266WiFi.h>
#define MAX_CLIENT 2
#define PORT 23
const char* ssid="view10";
const char* pwd="12312312333";
WiFiServer server(PORT);
WiFiClient serverClients[MAX_CLIENT];
void setup()
{
  WiFi.begin(ssid,pwd);
  Serial.begin(115200);
  uint8_t i=0;
  while(WiFi.status()!=WL_CONNECTED && i++<20)
  {
    delay(500);
  }
  if(i==21)
  {
    Serial.print("Could not connect to");
    Serial.println(ssid);
    while(true);
  }
  server.begin();
  server.setNoDelay(true);
  Serial.print("Use telnet with IP:");
  Serial.print(WiFi.localIP());
  Serial.print("and Port:");
  Serial.println(PORT);
}
void loop()
{
    uint8_t i;
    if(server.hasClient())
    {
      for(i=0;i<MAX_CLIENT;i++)
      {
        if(!serverClients[i] || !serverClients[i].connected())
        {
          if(serverClients[i])
          {
            serverClients[i].stop();
          }
          serverClients[i]=server.available();
          Serial.print("New client:");
          Serial.println(i);
          continue;
        }
      }
      WiFiClient serverClient=server.available();
      serverClient.stop();
    }
    for(i=0;i<MAX_CLIENT;i++)
    {
      if(serverClients[i] && !serverClients[i].connected())
      {
        if(serverClients[i].available()){
          while(serverClients[i].available())
          {
            Serial.println(serverClients[i].readString());
          }
        }
      }
      if(Serial.available())
      {
        size_t len=Serial.available();
        uint8_t sbuf[len];
        Serial.readBytes(sbuf,len);
        for(i=0;i<MAX_CLIENT;i++)
        {
          if(serverClients[i] && serverClients[i].connected())
          {
            serverClients[i].write(sbuf,len);
          }
        }
      }
    }
}
