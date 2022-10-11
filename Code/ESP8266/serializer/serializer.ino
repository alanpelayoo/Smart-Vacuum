
#include <ArduinoJson.h>

void SerializeObject()
{
    String json;
    StaticJsonDocument<300> doc;
    doc["text"] = "myText";
    doc["id"] = 10;
    doc["status"] = true;
    doc["value"] = 3.14;

    serializeJson(doc, json);
    Serial.println(json);
}

void DeserializeObject()
{
    String json = "{\"text\":\"myText\",\"id\":10,\"status\":true,\"value\":3.14}";

    StaticJsonDocument<300> doc;
    DeserializationError error = deserializeJson(doc, json);
    if (error) { return; }

    String text = doc["text"];
    int id = doc["id"];
    bool stat = doc["status"];
    float value = doc["value"];

    Serial.println(text);
    Serial.println(id);
    Serial.println(stat);
    Serial.println(value);
}

void setup()
{
    delay(1000);
    Serial.begin(115200);
    Serial.println("===== Object Example =====");
    Serial.println("-- Serialize --");
    SerializeObject();
    /*
    Serial.println();
    Serial.println("-- Deserialize --");
    DeserializeObject();
    */
}

void loop()
{
  
}
