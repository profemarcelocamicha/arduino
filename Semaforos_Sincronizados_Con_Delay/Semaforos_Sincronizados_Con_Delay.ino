// Pines del semáforo A
const int verdeA = 2;
const int amarilloA = 3;
const int rojoA = 4;

// Pines del semáforo B
const int verdeB = 5;
const int amarilloB = 6;
const int rojoB = 7;

void setup() {
  // Configurar todos los pines como salida
  pinMode(verdeA, OUTPUT);
  pinMode(amarilloA, OUTPUT);
  pinMode(rojoA, OUTPUT);
  pinMode(verdeB, OUTPUT);
  pinMode(amarilloB, OUTPUT);
  pinMode(rojoB, OUTPUT);
}

void loop() {
  // 1️⃣ 
  digitalWrite(verdeA, HIGH);
  digitalWrite(rojoB, HIGH);
  digitalWrite(amarilloA, LOW);   
  delay(5000); // 5 segundos

  // 2️⃣ 
  digitalWrite(verdeA, LOW);
  digitalWrite(amarilloA, HIGH);
  delay(2000); // 2 segundos

  // 3️⃣ 
  digitalWrite(amarilloA, LOW);
  digitalWrite(rojoA, HIGH);
  delay(1000);

  // 4️⃣ 
  digitalWrite(amarilloB, HIGH);
  digitalWrite(rojoB, LOW);
  delay(2000); // 2 segundos

  // 5️⃣ 
  digitalWrite(amarilloB, LOW);
  digitalWrite(verdeB, HIGH);
  delay(5000);

  // 6️⃣ 
  digitalWrite(verdeB, LOW);
  digitalWrite(amarilloB, HIGH);
  delay(2000);

  // 7️⃣ 
  digitalWrite(amarilloB, LOW);
  digitalWrite(rojoB, HIGH);
  delay(1000);

  // 8️⃣ 
  digitalWrite(rojoA, LOW); 
  digitalWrite(amarilloA, HIGH); 
  delay(2000);
 }
