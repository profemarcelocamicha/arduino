const int primerPin = 2;
const int ultimoPin = 11;
String entrada = "";

void setup() {
  Serial.begin(9600);
  for (int pin = primerPin; pin <= ultimoPin; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW); // Apagar todos al inicio
  }
  Serial.println("Ingrese los pines de los LEDs a encender (ej: 3 o 4,5,8):");
}

void loop() {
  if (Serial.available()) {
    entrada = Serial.readStringUntil('\n'); // Leer hasta Enter
    entrada.trim(); // Eliminar espacios innecesarios

    // Apagar todos los LEDs antes de encender los nuevos
    for (int pin = primerPin; pin <= ultimoPin; pin++) {
      digitalWrite(pin, LOW);
    }

    // Separar los números por coma
    int index = 0;
    while (index < entrada.length()) {
      int coma = entrada.indexOf(',', index);
      String numeroStr;
      if (coma == -1) {
        numeroStr = entrada.substring(index);
        index = entrada.length();
      } else {
        numeroStr = entrada.substring(index, coma);
        index = coma + 1;
      }

      int pinLed = numeroStr.toInt();
      if (pinLed >= primerPin && pinLed <= ultimoPin) {
        digitalWrite(pinLed, HIGH);
      } else {
        Serial.print("Pin inválido: ");
        Serial.println(pinLed);
      }
    }

    Serial.println("Listo. Puede ingresar nuevos pines:");
  }
}
