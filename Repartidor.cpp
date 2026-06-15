// Definimos el pin GPIO 23 para controlar el módulo MOSFET
const int pinMotor = 18; 

void setup() {
  // Configuramos el GPIO 23 como salida de señal
  pinMode(pinMotor, OUTPUT);
}

void loop() {
  analogWrite(pinMotor, 255)
  // 1. ACELERACIÓN PROGRESIVA
  // El valor va desde 0 (completamente apagado) hasta 255 (máxima velocidad)
  //for (int velocidad = 0; velocidad <= 255; velocidad++) {
  //  analogWrite(pinMotor, velocidad); // Envía la señal PWM al MOSFET
  //  delay(20);                        // Pausa de 20ms entre pasos (aprox. 5 segundos en total)
  //}

  // 2. VELOCIDAD MÁXIMA CONSTANTE
  // El motor se mantiene girando al 100% durante 3 segundos
  //delay(3000); 

  // 3. DESACELERACIÓN PROGRESIVA
  // El valor baja desde 255 hasta 0 para frenar suavemente
  //for (int velocidad = 255; velocidad >= 0; velocidad--) {
  //  analogWrite(pinMotor, velocidad);
  //  delay(20);                        // Pausa de 20ms entre pasos
  //}

  // 4. TIEMPO DE ESPERA APAGADO
  // El motor se queda detenido 2 segundos antes de volver a empezar el ciclo
  //delay(2000); 
}