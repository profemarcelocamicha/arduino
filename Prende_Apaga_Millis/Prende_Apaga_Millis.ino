int led = 13; // LED integrado
unsigned long intervalo = 1000; // 1 segundo
unsigned long tiempoAnterior = 0;
bool estadoLed = false;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  unsigned long tiempoActual = millis();

  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;     // Guardar tiempo del último cambio
    estadoLed = !estadoLed;             // Cambiar de encendido a apagado o viceversa
    digitalWrite(led, estadoLed);       // Aplicar el cambio al LED
  }
