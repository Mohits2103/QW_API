
#ifdef ESP32
  #include <WiFi.h>
  #include <HTTPClient.h>
#else
  #include <WiFi.h>
  #include <HTTPClient.h>
  #include <WiFiClient.h>
#endif

#include <Wire.h>

// Replace with your network credentials
const char* ssid     = "SSID";
const char* password = "PASSWORD";

// REPLACE with your Domain name and URL path or IP address with path
const char* serverName = "https://apim.quickwork.co/********************";


void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

 
}

void loop() {
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    
    // Your Domain name with URL path or IP address with path
    http.begin(serverName);
    
   http.addHeader("Content-Type", "application/json");
  http.addHeader("apiKey", "*********************************");
  int temperature = random(25,39);
  String x = "{\"Temp\":" + String(temperature) + "}";
  Serial.print(x);
  int httpResponseCode = http.POST(x);
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  //Send an HTTP POST request every 30 seconds
  delay(10000);  
}
