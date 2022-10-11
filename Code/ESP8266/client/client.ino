#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Totalplay-18Ax_2.4Gnormal";
const char* password = "pelayo02XX";

String url2 = "http://192.168.100.3:8000/api/";
String url = "http://www.google.com";

HTTPClient http;
WiFiClient client;

void setup()
{
   Serial.begin(115200);
   Serial.println(" ");
   delay(10);
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED){
      delay(500);
   }
   
}
void loop()
{
   get_id("1/");
   delay(1000);
}

void get_all(){
  http.begin(client, url2 + "sensors/"); //Iniciar conexión
  
  int httpCode = http.GET();  // Realizar petición
  if (httpCode == HTTP_CODE_OK) {
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    String payload = http.getString();   // Obtener respuesta
    Serial.println(payload);   // Mostrar respuesta por serial
  }
  http.end();
}

void get_id(String id){
  http.begin(client, url2 + "sensors/"+ id); //Iniciar conexión
  
  int httpCode = http.GET();  // Realizar petición
  if (httpCode == HTTP_CODE_OK) {
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    String payload = http.getString();   // Obtener respuesta
    Serial.println(payload);   // Mostrar respuesta por serial
  }
  http.end();
}
