// Definición de pines
const int trigPin = 9;
const int echoPin = 10;

// Variable para el tiempo y la distancia
long duracion;
int distancia;

void setup() {
  // Configuración de pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Comunicación serie para mostrar los datos
  Serial.begin(9600);
}

void loop() {
  // Limpia el pin TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Envía pulso de 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee el tiempo que tarda el pulso en volver
  duracion = pulseIn(echoPin, HIGH);

  // Calcular distancia (velocidad del sonido = 340 m/s)
  distancia = duracion * 0.034 / 2;

  // Mostrar distancia en el monitor serie
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm \r");

  delay(1000); // Espera medio segundo
}
