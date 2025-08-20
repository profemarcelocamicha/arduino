int ledInicio = 2;
int ledFin = 11;

void setup() {
  Serial.begin(9600);
  for (int pin = ledInicio; pin <= ledFin; pin++) {
    pinMode(pin, OUTPUT);
  }
  Serial.println("Ingrese: pin,tiempo_ms,si/no");
}

void loop() {
  if (Serial.available()) {
    String entrada = Serial.readStringUntil('\n');
    entrada.trim(); // elimina espacios y saltos de línea

    // Busca las comas
    int coma1 = entrada.indexOf(',');
    int coma2 = entrada.indexOf(',', coma1 + 1);

    if (coma1 > 0 && coma2 > coma1) {
      // Extrae valores
      int pinLed = entrada.substring(0, coma1).toInt();
      int tiempo = entrada.substring(coma1 + 1, coma2).toInt();
      String titilar = entrada.substring(coma2 + 1);
      titilar.toLowerCase();

      // Verifica rango de pin
      if (pinLed >= ledInicio && pinLed <= ledFin) {
        if (titilar == "no") {
          digitalWrite(pinLed, HIGH);
          delay(tiempo);
          digitalWrite(pinLed, LOW);
        } 
        else if (titilar == "si") {
          unsigned long tiempoInicio = millis();
          while (millis() - tiempoInicio < tiempo) {
            digitalWrite(pinLed, HIGH);
            delay(500);
            digitalWrite(pinLed, LOW);
            delay(500);
          }
        }
      } else {
        Serial.println("Error: pin fuera de rango (2 a 11).");
      }
    } else {
      Serial.println("Formato incorrecto. Ejemplo: 5,2000,si");
    }
  }
}
