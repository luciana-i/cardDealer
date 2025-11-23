#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Personal-WiFi-D0B-2.4Ghz";
const char* password = "acanoDeberiasentrar0.";

WebServer server(80);

void handleLED() {
  digitalWrite(2, !digitalRead(2));
  server.send(200, "text/plain", "LED toggled");
}

void setup() {

  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("Conectando a WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado!");
  Serial.print("IP asignada: ");
  Serial.println(WiFi.localIP());

  pinMode(2, OUTPUT);
  WiFi.begin(ssid, password);

  server.on("/led", handleLED);
  server.begin();
}

void loop() {
  server.handleClient();
}