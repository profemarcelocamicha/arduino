#include "DHT.h"

#define DHTPIN 2        // Pin del sensor DHT11
#define DHTTYPE DHT11

#define LED_VERDE 8
#define LED_AMARILLO 9
#define LED_ROJO 10

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);

  Serial.println("Sistema de temperatura con semáforo iniciado");
}

void loop() {
  delay(2000); // Espera entre lecturas

  float temp = dht.readTemperature(); // Temperatura en °C

  if (isnan(temp)) {
    Serial.println("Error al leer el sensor DHT11");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" °C");

  // Control del semáforo según temperatura
  if (temp < 26) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, LOW);
  } 
  else if (temp < 32) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, HIGH);
    digitalWrite(LED_ROJO, LOW);
  } 
  else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, HIGH);
  }
}
