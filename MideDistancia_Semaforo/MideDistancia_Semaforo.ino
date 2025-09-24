// Pines del HC-SR04
const int trigPin = 9;
const int echoPin = 10;

// Pines del semáforo
const int rojo = 2;
const int amarillo = 3;
const int verde = 4;

long duracion;
int distancia;

void setup() {
  // Configuración pines sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Configuración pines semáforo
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Enviar pulso ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer tiempo de regreso del eco
  duracion = pulseIn(echoPin, HIGH);

  // Calcular distancia en cm
  distancia = duracion * 0.034 / 2;

  // Mostrar distancia en el monitor serie (una sola línea)
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm   \r");

  // Lógica del semáforo
  if (distancia <= 10) {
    digitalWrite(rojo, HIGH);
    digitalWrite(amarillo, LOW);
    digitalWrite(verde, LOW);
  } else if (distancia <= 20) {
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, HIGH);
    digitalWrite(verde, LOW);
  } else {
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(verde, HIGH);
  }

  delay(150); // Pequeño retardo para estabilidad
}
