const int PIN_IR = 23; 

void setup() {
  Serial.begin(115200);
  
  // Usamos INPUT_PULLUP para asegurar el 1 cuando esté despejado
  pinMode(PIN_IR, INPUT_PULLUP); 
  
  Serial.println("--- Mezclador: Sensor IR Listo ---");
}

void loop() {
  int estadoSensor = digitalRead(PIN_IR);
  
  // Si es 0 (LOW), es porque acercamos la mano/carta
  if (estadoSensor == LOW) {
    Serial.println("¡Carta detectada!");
  } 
  // Si es 1 (HIGH), está despejado
  else {
    Serial.println("Despejado...");
  }
  
  delay(200);
}