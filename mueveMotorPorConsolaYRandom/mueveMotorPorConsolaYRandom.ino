#include <Servo.h>

Servo flecha;
int angulo = 90;  // Posición inicial

void setup() {
  Serial.begin(9600);
  flecha.attach(9);
  flecha.write(angulo);

  // Inicializar semilla para random
  randomSeed(analogRead(0));

  Serial.println("Juego de la flecha:");
  Serial.println("Ingresa un angulo entre 1 y 180, o 's' para mover aleatoriamente.");
}

void loop() {
  if (Serial.available() > 0) {
    String entrada = Serial.readStringUntil('\n');  // Leer hasta Enter
    entrada.trim();  // Quitar espacios o saltos

    if (entrada == "s" || entrada == "S") {
      angulo = random(1, 181);  // Número aleatorio entre 1 y 180
      Serial.print("Flecha movida a (random): ");
      Serial.println(angulo);
      flecha.write(angulo);
    }
    else {
      int valor = entrada.toInt();  // Convertir texto a número
      if (valor > 0 && valor <= 180) {
        angulo = valor;
        flecha.write(angulo);
        Serial.print("Flecha movida a: ");
        Serial.println(angulo);
      } else {
        Serial.println("Error: Ingresa un valor entre 1 y 180 o 's'.");
      }
    }
  }
}
