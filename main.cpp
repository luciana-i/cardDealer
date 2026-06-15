#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "¨¨¨¨¨¨z";
const char* password = "¨¨¨¨";

WebServer server(80);

void handleLED() {
  digitalWrite(2, !digitalRead(2));
  server.sendHeader("Access-Control-Allow-Origin", "*"); // CORS
  server.send(200, "text/plain", "LED toggled");
}

void setup() {
  Serial.begin(115200);
  delay(1000);

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

  // suscripcion de rutas aceptadas por esp32
  server.on("/led", HTTP_GET, handleLED);

  server.begin();
}

void loop() {
  server.handleClient();
}






