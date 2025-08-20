#include <Servo.h>

#define PINSERVO9 9
#define PINSERVO10 10
#define PINSERVO11 11

int PULSOMIN = 800;
int PULSOMAX = 2000;
Servo servo9;
Servo servo10;
Servo servo11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo9.attach(PINSERVO9, PULSOMIN, PULSOMAX);
  servo10.attach(PINSERVO10, PULSOMIN, PULSOMAX);  
  servo11.attach(PINSERVO11, PULSOMIN, PULSOMAX);    
}

void loop() {
//levanta las patas  
      levantaPatas(33, "izquierda");
      avanzaDerecha(0, "adelante");      
      avanzaIzquierda(0, "atras");                  
      levantaPatas(67, "derecha");
      avanzaIzquierda(90, "adelante");            
      avanzaDerecha(90, "atras");            


}

void levantaPatas(int angulo, String verbo) {
  servo10.write(angulo);
  // servo2.write(angulo);  
  String strB = "Patas: ";
  strB += verbo;
  strB += " - angulo: ";
  strB += angulo;
  Serial.println(strB.c_str());
  delay(50);
}

void avanzaDerecha(int angulo, String verbo) {
  servo9.write(angulo);
  // servo2.write(angulo);  
  String strB = "Patas: ";
  strB += verbo;
  strB += " - angulo: ";
  strB += angulo;
  Serial.println(strB.c_str());
  delay(50);
}

void avanzaIzquierda(int angulo, String verbo) {
  servo11.write(angulo);
  // servo2.write(angulo);  
  String strB = "Patas: ";
  strB += verbo;
  strB += " - angulo: ";
  strB += angulo;
  Serial.println(strB.c_str());
  delay(50);
}



