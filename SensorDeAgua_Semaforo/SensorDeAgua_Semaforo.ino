int pinSensor = A0;
int valorSensor = 0;

// Pines de los LEDs
int ledVerde = 8;
int ledAmarillo = 9;
int ledRojo = 10;

void setup() {
  Serial.begin(9600);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
}

void loop() {
  valorSensor = analogRead(pinSensor);

  if (valorSensor < 250) {
    // Encender VERDE
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, LOW);
    Serial.print("Verde - Valor: ");
  } 
  else if (valorSensor < 300) {
    // Encender AMARILLO
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(ledRojo, LOW);
    Serial.print("Amarillo - Valor: ");
  } 
  else {
    // Encender ROJO
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, HIGH);
    Serial.print("Rojo - Valor: ");
  }

  Serial.println(valorSensor);
  delay(1000);
}
