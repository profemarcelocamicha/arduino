#include <Servo.h>

Servo flecha;
int jugadores;            // cantidad de jugadores
int posiciones[14];       // hasta 14 jugadores
int activos[14];          // jugadores activos (1 = sigue, 0 = eliminado)
int vivos;                // cuántos quedan en juego

void setup() {
  Serial.begin(9600);
  flecha.attach(9);
  flecha.write(90);  // centro inicial
  Serial.println("=== Juego del Calamar (Arduino) ===");
  Serial.println("Ingresa la cantidad de jugadores (max 14):");
}

void loop() {
  if (Serial.available() > 0) {
    jugadores = Serial.parseInt();

    if (jugadores > 1 && jugadores <= 14) {
      iniciarJuego(jugadores);
      jugar();
      Serial.println("=== Fin del Juego ===");
    } else {
      Serial.println("Error: ingresa un numero entre 2 y 14.");
    }

    // Limpiar el buffer
    while (Serial.available() > 0) Serial.read();
  }
}

void iniciarJuego(int n) {
  vivos = n;

  // calcular posiciones equidistantes
  int paso = 180 / (n - 1);
  for (int i = 0; i < n; i++) {
    posiciones[i] = i * paso;
    activos[i] = 1; // todos activos
  }

  Serial.print("Jugadores: ");
  Serial.println(n);
  Serial.println("Posiciones asignadas:");
  for (int i = 0; i < n; i++) {
    Serial.print("Jugador ");
    Serial.print(i + 1);
    Serial.print(" -> ");
    Serial.print(posiciones[i]);
    Serial.println(" grados");
  }
}

void jugar() {
  while (vivos > 1) {
    delay(2000); // pausa entre rondas

    int elegido;
    do {
      elegido = random(0, jugadores);  // elige un índice
    } while (activos[elegido] == 0);   // repetir hasta encontrar uno vivo

    // Mover el servo
    flecha.write(posiciones[elegido]);
    delay(1000);

    // Eliminar jugador
    activos[elegido] = 0;
    vivos--;

    Serial.print("Jugador ");
    Serial.print(elegido + 1);
    Serial.println(" eliminado ❌");
  }

  // Buscar al ganador
  for (int i = 0; i < jugadores; i++) {
    if (activos[i] == 1) {
      Serial.print("🎉 ¡Jugador ");
      Serial.print(i + 1);
      Serial.println(" es el GANADOR! 🎉");
    }
  }
}
