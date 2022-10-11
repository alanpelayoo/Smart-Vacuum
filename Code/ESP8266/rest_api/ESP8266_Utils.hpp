void ConnectWiFi_STA(bool useStaticIP = false)
{
   Serial.println("Starting Connection");
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED){
      delay(500);
   }
}
