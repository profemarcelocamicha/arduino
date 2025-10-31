#include <Servo.h>

Servo motor;
int angulo = 0;

void setup() {

  Serial.begin(9600);
  //motor.attach(9);          // pin de señal del servo
  Serial.println("Ingresa un angulo entre 1 y 180:");
}

void loop() {
  if (Serial.available() > 0) {
    angulo = Serial.parseInt();         // leer número desde consola
    if (angulo > 0 && angulo <= 180) {
      motor.attach(9);  // conecta el servo      
      motor.write(angulo);
      Serial.print("Servo en ");
      Serial.print(angulo);
      Serial.println(" grados");
      delay(500);
      motor.detach();      
    } else {
      Serial.println("Error: ingresa un valor entre 1 y 180.");
    }
  }
}
