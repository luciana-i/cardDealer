const int soundPin = 22; // DO del sensor de sonido
const int led = 2;       // LED integrado del ESP32 (GPIO2)

void setup() {
  Serial.begin(115200);

  pinMode(soundPin, INPUT);
  pinMode(led, OUTPUT);

  Serial.println("Detectando sonido...");
}

void loop() {
  int sonido = digitalRead(soundPin);

  /*if (sonido == HIGH) {
    Serial.println("¡Aplauso detectado!");
    digitalWrite(led, HIGH);
    delay(200);  // evita múltiples detecciones por rebote
  } else {
    digitalWrite(led, LOW);
  }
  */
  int valor = digitalRead(soundPin);
  Serial.println(valor);
  delay(200);
}