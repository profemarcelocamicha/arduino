#include <Servo.h>

Servo motor;  

const int sensor1 = 2;  // Sensor infrarrojo en pin 2
const int sensor2 = 3;  // Sensor infrarrojo en pin 3
const int pinMotor = 9; // Servo motor en pin 9

void setup() {
  motor.attach(pinMotor);  

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  motor.write(0); // Posición inicial
}

void loop() {
  int estadoSensor1 = digitalRead(sensor1);
  int estadoSensor2 = digitalRead(sensor2);

  if (estadoSensor1 == LOW) {  
    motor.write(45);     // Mueve a 1°
    delay(2000);        // Espera 2 segundos
    motor.write(0);     // Vuelve a 0°
  } 
  else if (estadoSensor2 == LOW) {
    motor.write(120);    // Mueve a 90°
    delay(2000);        // Espera 2 segundos
    motor.write(0);     // Vuelve a 0°
  }
}
