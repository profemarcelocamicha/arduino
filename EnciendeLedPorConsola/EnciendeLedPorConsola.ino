const int primerPin = 2;
const int ultimoPin = 11;
String entrada = "";

void setup() {
  Serial.begin(9600);
  // Configurar todos los pines como salida y apagarlos
  for (int pin = primerPin; pin <= ultimoPin; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  Serial.println("Ingrese el número del pin (2 a 11) para encender un LED:");
}

void loop() {
  if (Serial.available()) {
    entrada = Serial.readStringUntil('\n');  // Leer hasta Enter
    entrada.trim();  // Eliminar espacios en blanco
    int pinSeleccionado = entrada.toInt();  // Convertir a número

    // Verificar que esté dentro del rango permitido
    if (pinSeleccionado >= primerPin && pinSeleccionado <= ultimoPin) {
      // Apagar todos los LEDs
      for (int pin = primerPin; pin <= ultimoPin; pin++) {
        digitalWrite(pin, LOW);
      }

      // Encender el LED indicado
      digitalWrite(pinSeleccionado, HIGH);
      Serial.print("LED encendido en el pin ");
      Serial.println(pinSeleccionado);
    } else {
      Serial.println("Número de pin inválido. Ingrese un número del 2 al 11.");
    }
  }
}
