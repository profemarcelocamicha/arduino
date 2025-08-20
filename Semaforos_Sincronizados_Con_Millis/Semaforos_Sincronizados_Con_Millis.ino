// Pines semáforo 1 (Calle A)
const int rojo1 = 2;
const int amarillo1 = 3;
const int verde1 = 4;

// Pines semáforo 2 (Calle B)
const int rojo2 = 5;
const int amarillo2 = 6;
const int verde2 = 7;

// Control de tiempos
unsigned long tiempoAnterior = 0;
unsigned long duracionEstado = 0;
int estado = 0;

void setup() {
  pinMode(rojo1, OUTPUT);
  pinMode(amarillo1, OUTPUT);
  pinMode(verde1, OUTPUT);

  pinMode(rojo2, OUTPUT);
  pinMode(amarillo2, OUTPUT);
  pinMode(verde2, OUTPUT);

  Serial.begin(9600);

  actualizarSemaforos(estado);
}

void loop() {
  unsigned long ahora = millis();

  if (ahora - tiempoAnterior >= duracionEstado) {
    estado = (estado + 1) % 6;
    actualizarSemaforos(estado);
    tiempoAnterior = ahora;
  }


  // Acá podés manejar otras tareas sin bloquear el sistema
}

void actualizarSemaforos(int est) {
  switch (est) {
    case 0:
      // S1: Rojo | S2: Verde
      setS1(HIGH, LOW, LOW);
      setS2(LOW, LOW, HIGH);
      duracionEstado = 5000;
      break;

    case 1:
      // S1: Rojo | S2: Amarillo
      setS1(HIGH, LOW, LOW);
      setS2(LOW, HIGH, LOW);
      duracionEstado = 2000;
      break;

    case 2:
      // S1: Rojo + Amarillo | S2: Rojo
      setS1(HIGH, HIGH, LOW);
      setS2(HIGH, LOW, LOW);
      duracionEstado = 2000;
      break;

    case 3:
      // S1: Verde | S2: Rojo
      setS1(LOW, LOW, HIGH);
      setS2(HIGH, LOW, LOW);
      duracionEstado = 5000;
      break;

    case 4:
      // S1: Amarillo | S2: Rojo
      setS1(LOW, HIGH, LOW);
      setS2(HIGH, LOW, LOW);
      duracionEstado = 2000;
      break;

    case 5:
      // S1: Rojo | S2: Rojo + Amarillo
      setS1(HIGH, LOW, LOW);
      setS2(HIGH, HIGH, LOW);
      duracionEstado = 2000;
      break;
  }
}

void setS1(bool r, bool a, bool v) {
  digitalWrite(rojo1, r);
  digitalWrite(amarillo1, a);
  digitalWrite(verde1, v);
}

void setS2(bool r, bool a, bool v) {
  digitalWrite(rojo2, r);
  digitalWrite(amarillo2, a);
  digitalWrite(verde2, v);
}
