#include <Bonezegei_DHT11.h>
#include <Servo.h>


//#define DHTTYPE DHT11 //Cambiar DHT22 por DHT11 si tienes este sensor
//#define DHTPIN 


#define LED_SEMA_VE_I 9
#define LED_SEMA_AM_I 10
#define LED_SEMA_RO_I 2

#define LED_SEMA_VE_D 3
#define LED_SEMA_AM_D 4
#define LED_SEMA_RO_D 5

#define MOV_PIN 13
#define LED_MOV_PIN 7
#define DHTPIN 8
#define INCLINA_PIN 11
#define BUZ_INCLINA_PIN 6
#define PINSERVO 12

unsigned long x = millis();
unsigned long previousTime = millis();
int PULSOMIN = 550;
int PULSOMAX = 2500;
Bonezegei_DHT11 dht(DHTPIN);
Servo servo1;
boolean barreraEstado = true;

void setup() {
  // put your setup code here, to run once:
 
  pinMode(LED_SEMA_VE_I, OUTPUT);
  pinMode(LED_SEMA_AM_I, OUTPUT);
  pinMode(LED_SEMA_RO_I, OUTPUT);
  pinMode(LED_SEMA_VE_D, OUTPUT);
  pinMode(LED_SEMA_AM_D, OUTPUT);
  pinMode(LED_SEMA_RO_D, OUTPUT);
  pinMode(MOV_PIN, INPUT);
  pinMode(LED_MOV_PIN, OUTPUT);
  pinMode(DHTPIN, INPUT);
  pinMode(INCLINA_PIN, INPUT_PULLUP);  
  pinMode(BUZ_INCLINA_PIN, OUTPUT);  

  Serial.begin(9600);
  dht.begin();

  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);

}

void loop() {

  // SENSOR DE iNCLINACIÓN
  if (digitalRead(INCLINA_PIN) == LOW) 
  {
    digitalWrite(BUZ_INCLINA_PIN, HIGH);
  } 
  else 
  {
    digitalWrite(BUZ_INCLINA_PIN, LOW);
  };

  // SENSOR DE TEMPERATURA

  if ((x > 0) && (x <= 10)) {

  if (dht.getData()) {                         // get All data from DHT11
    float tempDeg = dht.getTemperature();      // return temperature in celsius
    float tempFar = dht.getTemperature(true);  // return temperature in fahrenheit if true celsius of false
    int hum = dht.getHumidity();               // return humidity
    String str  = "Temperature: ";
           str += tempDeg;
           str += "°C  ";
           str += tempFar;
           str += "°F  Humidity:";
           str += hum;
    Serial.println(str.c_str());
    //Serial.printf("Temperature: %0.1lf°C  %0.1lf°F Humidity:%d \n", tempDeg, tempFar, hum);
  }
  //delay(2000);  //delay atleast 2 seconds for DHT11 to read tha data

  };


  // SERVOMOTOR 1
if ((x > 0) && (x <= 1000)) {
  if (barreraEstado) {
    barrera1(0, "cerrar");    
  }
}

if ((x > 10000) && (x <= 11000)) {
  if (barreraEstado == false) {
    barrera1(90, "abrir");   
  }
}



  // SENSOR DE MOVIMIENTO

  if (digitalRead(MOV_PIN) == HIGH) {
    digitalWrite(LED_MOV_PIN, HIGH);
  } else {
    digitalWrite(LED_MOV_PIN, LOW);
  };

  // SEMAFOROS
  unsigned long currentTime = millis();
  x = currentTime - previousTime;

  if ((x > 0) && (x <= 3000)) {
    digitalWrite(LED_SEMA_RO_D, HIGH);
  };

  if ((x > 1000) && (x <= 2000)) {
    digitalWrite(LED_SEMA_RO_I, LOW);
    digitalWrite(LED_SEMA_AM_I, HIGH);
  };

  if ((x > 2000) && (x <= 3000)) {
    digitalWrite(LED_SEMA_AM_I, LOW);
  };

  if ((x > 3000) && (x <= 6000)) {
    digitalWrite(LED_SEMA_VE_I, HIGH);
  };

  if ((x > 6000) && (x <= 7000)) {
    digitalWrite(LED_SEMA_VE_I, LOW);
    digitalWrite(LED_SEMA_AM_I, HIGH);
  };

  if ((x > 7000) && (x <= 8000)) {
    digitalWrite(LED_SEMA_AM_I, LOW);
  };

  if ((x > 8000) && (x <= 11000)) {
    digitalWrite(LED_SEMA_RO_I, HIGH);
  };

  if ((x > 11000) && (x <= 12000)) {
    digitalWrite(LED_SEMA_RO_D, LOW);
  };

  if ((x > 12000) && (x <= 13000)) {
    digitalWrite(LED_SEMA_AM_D, HIGH);
  };

  if ((x > 13000) && (x <= 14000)) {
    digitalWrite(LED_SEMA_AM_D, LOW);
  };

  if ((x > 14000) && (x <= 17000)) {
    digitalWrite(LED_SEMA_VE_D, HIGH);
  };

  if ((x > 17000) && (x <= 18000)) {
    digitalWrite(LED_SEMA_VE_D, LOW);
  };

  if ((x > 18000) && (x <= 19000)) {
    digitalWrite(LED_SEMA_AM_D, HIGH);
  };

  if ((x > 19000) && (x <= 20000)) {
    digitalWrite(LED_SEMA_AM_D, LOW);
  };

  if (x > 20000) {
    previousTime = millis();
  };
}

void barrera1(int angulo, String verbo){
    servo1.write(angulo);
    String strB  = "Barrera: ";
           strB += verbo;    
           strB += " - angulo: ";    
           strB += angulo;               
    Serial.println(strB.c_str());
    barreraEstado = !barreraEstado;    
}
