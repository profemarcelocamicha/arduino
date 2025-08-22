// Pines de los LEDs
const int LED_ROJO = 5;
const int LED_AMARILLO = 6;
const int LED_VERDE = 7;

// Intervalos en milisegundos
const unsigned long INTERVALO_ROJO = 100;   // 0,5 segundos
const unsigned long INTERVALO_AMARILLO = 500; // 1 segundo
const unsigned long INTERVALO_VERDE = 2500;    // 2 segundos

// Variables para controlar el tiempo
unsigned long tiempoAnteriorRojo = 0;
unsigned long tiempoAnteriorAmarillo = 0;
unsigned long tiempoAnteriorVerde = 0;

// Estados actuales de cada LED
bool estadoRojo = LOW;
bool estadoAmarillo = LOW;
bool estadoVerde = LOW;

void setup() {
  Serial.begin(9600);  
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}

void loop() {
  unsigned long tiempoActual = millis();

  // LED ROJO
  if (tiempoActual - tiempoAnteriorRojo >= INTERVALO_ROJO) {
    tiempoAnteriorRojo = tiempoActual;     // actualizar referencia
    estadoRojo = !estadoRojo;              // invertir estado
    digitalWrite(LED_ROJO, estadoRojo);
    Serial.println("ROJO: " + String(estadoRojo));  
  }

  // LED AMARILLO
  if (tiempoActual - tiempoAnteriorAmarillo >= INTERVALO_AMARILLO) {
    tiempoAnteriorAmarillo = tiempoActual;
    estadoAmarillo = !estadoAmarillo;
    digitalWrite(LED_AMARILLO, estadoAmarillo);
    Serial.println("AMARILLO" + String(estadoAmarillo));    
  }

  // LED VERDE
  if (tiempoActual - tiempoAnteriorVerde >= INTERVALO_VERDE) {
    tiempoAnteriorVerde = tiempoActual;
    estadoVerde = !estadoVerde;
    digitalWrite(LED_VERDE, estadoVerde);
    Serial.println("VERDE" + String(estadoVerde));        
  }
}
