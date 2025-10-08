#include "DHT.h"   // Incluye la librería del sensor

#define DHTPIN 2        // Pin de datos conectado al DHT11
#define DHTTYPE DHT11   // Tipo de sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);   // Inicia comunicación serial
  dht.begin();          // Inicializa el sensor
  Serial.println("Sensor DHT11 iniciado");
}

void loop() {
  // Espera un poco entre mediciones
  delay(2000);

  // Lee humedad y temperatura
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature(); // Por defecto en °C

  // Verifica si hay error de lectura
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error al leer el sensor DHT11");
    return;
  }

  // Muestra los valores
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
}

