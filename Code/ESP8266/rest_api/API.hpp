String url2 = "http://192.168.100.3:8000/api/";
HTTPClient http;
WiFiClient client;

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
