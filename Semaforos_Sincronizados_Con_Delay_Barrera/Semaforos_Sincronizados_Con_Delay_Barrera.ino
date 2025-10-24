#include <Servo.h>  // Librería para controlar servos

// Pines del semáforo A
const int verdeA = 2;
const int amarilloA = 3;
const int rojoA = 4;

// Pines del semáforo B
const int verdeB = 5;
const int amarilloB = 6;
const int rojoB = 7;

// Servo motor (barrera)
Servo barrera;
const int pinBarrera = 9;  // pin de señal del servo

// Funciones para abrir/cerrar la barrera sin zumbido
void abrirBarrera() {
  barrera.attach(pinBarrera);  // conecta el servo
  barrera.write(90);           // abre (90 grados)
  delay(800);                  // espera a que llegue
  barrera.detach();            // corta la señal → no zumba
}

void cerrarBarrera() {
  barrera.attach(pinBarrera);
  barrera.write(180);            // cierra (0 grados)
  delay(800);
  barrera.detach();
}

void setup() {
  // Configurar pines de semáforo como salida
  pinMode(verdeA, OUTPUT);
  pinMode(amarilloA, OUTPUT);
  pinMode(rojoA, OUTPUT);
  pinMode(verdeB, OUTPUT);
  pinMode(amarilloB, OUTPUT);
  pinMode(rojoB, OUTPUT);

  // Barrera inicialmente cerrada
  cerrarBarrera();
}

void loop() {
  // 1️⃣ Semáforo A verde, B rojo → barrera cerrada
  digitalWrite(verdeA, HIGH);
  digitalWrite(amarilloA, LOW);
  digitalWrite(rojoA, LOW);
  digitalWrite(rojoB, HIGH);
  digitalWrite(verdeB, LOW);
  digitalWrite(amarilloB, LOW);
  cerrarBarrera(); // por seguridad
  delay(5000);

  // 2️⃣ A amarillo
  digitalWrite(verdeA, LOW);
  digitalWrite(amarilloA, HIGH);
  delay(2000);

  // 3️⃣ A rojo
  digitalWrite(amarilloA, LOW);
  digitalWrite(rojoA, HIGH);
  delay(1000);

  // 4️⃣ B amarillo
  digitalWrite(rojoB, LOW);
  digitalWrite(amarilloB, HIGH);
  cerrarBarrera(); // aún cerrada
  delay(2000);

  // 5️⃣ B verde → abrir barrera
  digitalWrite(amarilloB, LOW);
  digitalWrite(verdeB, HIGH);
  abrirBarrera();
  delay(5000);

  // 6️⃣ B amarillo → cerrar barrera
  digitalWrite(verdeB, LOW);
  digitalWrite(amarilloB, HIGH);
  cerrarBarrera();
  delay(2000);

  // 7️⃣ B rojo
  digitalWrite(amarilloB, LOW);
  digitalWrite(rojoB, HIGH);
  delay(1000);

  // 8️⃣ A amarillo
  digitalWrite(rojoA, LOW);
  digitalWrite(amarilloA, HIGH);
  delay(2000);
}
