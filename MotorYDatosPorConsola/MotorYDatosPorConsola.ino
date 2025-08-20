#include <Servo.h>

const int pinServo1 = 9;
const int pinServo2 = 8;

Servo barrera1;
Servo barrera2;

void setup() {
  Serial.begin(9600);

  // Posición inicial cerrada para ambas barreras
  barrera1.attach(pinServo1);
  barrera1.write(0);
  delay(300);
  barrera1.detach();

  barrera2.attach(pinServo2);
  barrera2.write(0);
  delay(300);
  barrera2.detach();

  Serial.println("Listo. Escribí 'abrir1', 'cerrar1', 'abrir2' o 'cerrar2'");
}

void loop() {
  if (Serial.available()) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando == "abrir1") {
      barrera1.attach(pinServo1);
      barrera1.write(90);
      delay(300);
      barrera1.detach();
      Serial.println("Barrera 1 abierta");
    }
    else if (comando == "cerrar1") {
      barrera1.attach(pinServo1);
      barrera1.write(0);
      delay(300);
      barrera1.detach();
      Serial.println("Barrera 1 cerrada");
    }
    else if (comando == "abrir2") {
      barrera2.attach(pinServo2);
      barrera2.write(70);
      delay(300);
      barrera2.detach();
      Serial.println("Barrera 2 abierta");
    }
    else if (comando == "cerrar2") {
      barrera2.attach(pinServo2);
      barrera2.write(0);
      delay(300);
      barrera2.detach();
      Serial.println("Barrera 2 cerrada");
    }
    else {
      Serial.println("Comando no reconocido");
    }
  }
}
