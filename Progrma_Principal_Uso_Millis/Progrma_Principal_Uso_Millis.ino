#include <Servo.h>

// Pines semáforo 1 (Calle A)
const int rojo1 = 2;
const int amarillo1 = 3;
const int verde1 = 4;

// Pines semáforo 2 (Calle B)
const int rojo2 = 5;
const int amarillo2 = 6;
const int verde2 = 7;

// Servos para barreras
Servo servo1;
Servo servo2;
const int pinServo1 = 8;
const int pinServo2 = 9;
const int BARRERA_CERRADA = 0;
const int BARRERA_ABIERTA = 90;

// Estados
unsigned long tiempoAnterior = 0;
unsigned long duracionEstado = 0;
int estado = 0;

// Modo mantenimiento (solo semáforos)
bool modoMantenimiento = false;
bool ledAmarilloOn = false;
unsigned long tiempoParpadeoAnterior = 0;
const unsigned long intervaloParpadeo = 500;

// Modo bloqueo total
bool modoBloqueo = false;

// Modo manual de barreras
bool modoManual1 = false;
bool modoManual2 = false;
int estadoManual1 = BARRERA_CERRADA;
int estadoManual2 = BARRERA_CERRADA;

// Modo automático de barreras activable/desactivable
bool modoAutomaticoBarreras = false;

// Últimos estados para optimización
int ultimoEstado1 = -1;
int ultimoEstado2 = -1;

void setup() {
  Serial.begin(9600);

  pinMode(rojo1, OUTPUT);
  pinMode(amarillo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(rojo2, OUTPUT);
  pinMode(amarillo2, OUTPUT);
  pinMode(verde2, OUTPUT);

  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo1.write(BARRERA_CERRADA);
  servo2.write(BARRERA_CERRADA);
  delay(300);
  servo1.detach();
  servo2.detach();

  actualizarSemaforos(estado);
  controlarBarreras(estado);
}

void loop() {
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando == "serviceOn") {
      modoMantenimiento = true;
      modoBloqueo = false;
      apagarTodos();
      Serial.println("🟡 Modo mantenimiento activado.");
    } else if (comando == "serviceOff") {
      modoMantenimiento = false;
      actualizarSemaforos(estado);
      controlarBarreras(estado);
      Serial.println("🟢 Modo mantenimiento desactivado.");
    }

    else if (comando == "bloqueoOn") {
      modoBloqueo = true;
      modoMantenimiento = false;
      apagarTodos();
      controlarBarreras(estado);
      Serial.println("⛔ Modo BLOQUEO TOTAL activado.");
    } else if (comando == "bloqueoOff") {
      modoBloqueo = false;
      actualizarSemaforos(estado);
      controlarBarreras(estado);
      Serial.println("✅ Modo BLOQUEO desactivado.");
    }

    else if (comando == "barrerasOff") {
      modoAutomaticoBarreras = false;
      Serial.println("🔕 Modo automático de barreras DESACTIVADO.");
    } else if (comando == "barrerasOn") {
      modoAutomaticoBarreras = true;
      controlarBarreras(estado);
      Serial.println("✅ Modo automático de barreras ACTIVADO.");
    }

    else if (comando == "abrir1") {
      modoManual1 = true;
      estadoManual1 = BARRERA_ABIERTA;
      controlarBarreras(estado);
      Serial.println("🚧 Barrera 1 abierta manualmente.");
    } else if (comando == "cerrar1") {
      modoManual1 = true;
      estadoManual1 = BARRERA_CERRADA;
      controlarBarreras(estado);
      Serial.println("🚧 Barrera 1 cerrada manualmente.");
    } else if (comando == "auto1") {
      modoManual1 = false;
      controlarBarreras(estado);
      Serial.println("🔄 Barrera 1 vuelve a modo automático.");
    }

    else if (comando == "abrir2") {
      modoManual2 = true;
      estadoManual2 = BARRERA_ABIERTA;
      controlarBarreras(estado);
      Serial.println("🚧 Barrera 2 abierta manualmente.");
    } else if (comando == "cerrar2") {
      modoManual2 = true;
      estadoManual2 = BARRERA_CERRADA;
      controlarBarreras(estado);
      Serial.println("🚧 Barrera 2 cerrada manualmente.");
    } else if (comando == "auto2") {
      modoManual2 = false;
      controlarBarreras(estado);
      Serial.println("🔄 Barrera 2 vuelve a modo automático.");
    }
  }

  if (modoBloqueo) {
    digitalWrite(rojo1, HIGH);
    digitalWrite(amarillo1, LOW);
    digitalWrite(verde1, LOW);
    digitalWrite(rojo2, HIGH);
    digitalWrite(amarillo2, LOW);
    digitalWrite(verde2, LOW);
    return;
  }

  if (modoMantenimiento) {
    unsigned long ahora = millis();
    if (ahora - tiempoParpadeoAnterior >= intervaloParpadeo) {
      ledAmarilloOn = !ledAmarilloOn;
      digitalWrite(rojo1, LOW);
      digitalWrite(verde1, LOW);
      digitalWrite(rojo2, LOW);
      digitalWrite(verde2, LOW);
      digitalWrite(amarillo1, ledAmarilloOn);
      digitalWrite(amarillo2, ledAmarilloOn);
      tiempoParpadeoAnterior = ahora;
    }
    return;
  }

  unsigned long ahora = millis();
  if (ahora - tiempoAnterior >= duracionEstado) {
    estado = (estado + 1) % 6;
    actualizarSemaforos(estado);
    controlarBarreras(estado);
    tiempoAnterior = ahora;
  }
}

void actualizarSemaforos(int est) {
  switch (est) {
    case 0:
      setS1(HIGH, LOW, LOW);
      setS2(LOW, LOW, HIGH);
      duracionEstado = 5000;
      break;
    case 1:
      setS1(HIGH, LOW, LOW);
      setS2(LOW, HIGH, LOW);
      duracionEstado = 2000;
      break;
    case 2:
      setS1(HIGH, HIGH, LOW);
      setS2(HIGH, LOW, LOW);
      duracionEstado = 2000;
      break;
    case 3:
      setS1(LOW, LOW, HIGH);
      setS2(HIGH, LOW, LOW);
      duracionEstado = 5000;
      break;
    case 4:
      setS1(LOW, HIGH, LOW);
      setS2(HIGH, LOW, LOW);
      duracionEstado = 2000;
      break;
    case 5:
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

void apagarTodos() {
  digitalWrite(rojo1, LOW);
  digitalWrite(amarillo1, LOW);
  digitalWrite(verde1, LOW);
  digitalWrite(rojo2, LOW);
  digitalWrite(amarillo2, LOW);
  digitalWrite(verde2, LOW);
}

void controlarBarreras(int estado) {
  int nuevoEstado1 = ultimoEstado1;
  int nuevoEstado2 = ultimoEstado2;

  if (modoBloqueo) {
    nuevoEstado1 = BARRERA_CERRADA;
    nuevoEstado2 = BARRERA_CERRADA;
  } else if (modoAutomaticoBarreras) {
    if (!modoManual1) nuevoEstado1 = (estado == 3) ? BARRERA_ABIERTA : BARRERA_CERRADA;
    if (!modoManual2) nuevoEstado2 = (estado == 0) ? BARRERA_ABIERTA : BARRERA_CERRADA;
  }

  if (modoManual1) nuevoEstado1 = estadoManual1;
  if (modoManual2) nuevoEstado2 = estadoManual2;

  if (nuevoEstado1 != ultimoEstado1) {
    servo1.attach(pinServo1);
    servo1.write(nuevoEstado1);
    delay(300);
    servo1.detach();
    ultimoEstado1 = nuevoEstado1;
  }

  if (nuevoEstado2 != ultimoEstado2) {
    servo2.attach(pinServo2);
    servo2.write(nuevoEstado2);
    delay(300);
    servo2.detach();
    ultimoEstado2 = nuevoEstado2;
  }
}
