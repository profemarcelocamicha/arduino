#include <Servo.h>

Servo barrera;         // Objeto servo
int anguloActual = 180;  // Guarda el último ángulo

void setup() {
  Serial.begin(9600);     // Comunicación serie
  barrera.attach(9);      // Pin del servo
  barrera.write(180);       // Posición inicial
  delay(500);
  barrera.detach();       // Se apaga después de moverse
  Serial.println("Ingrese un ángulo entre 1 y 180 grados:");
}

void loop() {
  if (Serial.available() > 0) {
    int nuevoAngulo = Serial.parseInt();  // Lee el número ingresado

    if (nuevoAngulo >= 1 && nuevoAngulo <= 180) {
      Serial.print("Moviendo barrera a ");
      Serial.print(nuevoAngulo);
      Serial.println(" grados...");

      barrera.attach(9);  // Se vuelve a conectar justo antes de moverse
      moverServoLento(barrera, anguloActual, nuevoAngulo, 10);
      delay(200);
      barrera.detach();   // Se desconecta para evitar zumbido

      anguloActual = nuevoAngulo;  // Guarda el nuevo ángulo
      Serial.println("Listo! Puede ingresar otro ángulo:");
    } 
    else {
      Serial.println("⚠️ Angulo fuera de rango. Ingrese un valor entre 1 y 180.");
    }
  }
}

// --- Función para mover el servo suavemente ---
void moverServoLento(Servo &servo, int desde, int hasta, int velocidad) {
  if (desde < hasta) {
    for (int ang = desde; ang <= hasta; ang++) {
      servo.write(ang);
      delay(velocidad);
    }
  } else {
    for (int ang = desde; ang >= hasta; ang--) {
      servo.write(ang);
      delay(velocidad);
    }
  }
}
