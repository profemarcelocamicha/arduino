#include <Servo.h>

const int pinPIR = 2;     // Sensor PIR - Movimiento
const int pinServo = 9;   // Servo - Motor de la barrera

Servo barrera;
int estadoMovimiento = LOW;

void setup() {
  barrera.attach(pinServo);
  pinMode(pinPIR, INPUT);
  Serial.begin(9600);
  barrera.write(0);  // posición inicial (cerrada)
}

void loop() {
  //estadoMovimiento = digitalRead(pinPIR);

  //if (estadoMovimiento == HIGH) {
    Serial.println("Movimiento detectado. Abriendo barrera...");
  //  barrera.write(100);  // Abrir barrera (ajustá el ángulo si querés)
    delay(3000);        // Esperar 3 segundos
    Serial.println("Cerrando barrera...");
  //  barrera.write(0);   // Cerrar barrera
    delay(3000);        // Evita rebotes
  //}
}