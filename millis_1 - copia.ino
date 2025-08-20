
#define LED_1_PIN 1
#define LED_2_PIN 2
#define LED_3_PIN 3
#define LED_4_PIN 11
#define LED_5_PIN 12
#define LED_6_PIN 13

unsigned long previousTimeLed1 = millis();
unsigned long previousTimeLed2 = millis();
unsigned long previousTimeLed3 = millis();
unsigned long previousTimeLed4 = millis();
unsigned long previousTimeLed5 = millis();
unsigned long previousTimeLed6 = millis();

long timeIntervalLed1 = 1000;
long timeIntervalLed2 = 1000;
long timeIntervalLed3 = 1000;
long timeIntervalLed4 = 1000;
long timeIntervalLed5 = 1000;
long timeIntervalLed6 = 3000;

int ledState1 = HIGH;
int ledState2 = HIGH;
int ledState3 = HIGH;
int ledState4 = HIGH;
int ledState5 = HIGH;
int ledState6 = HIGH;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  
  
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
  pinMode(LED_5_PIN, OUTPUT);  
  pinMode(LED_6_PIN, OUTPUT);    
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();

  // task 1
  if(currentTime - previousTimeLed1 > timeIntervalLed1) {
    previousTimeLed1 = currentTime;
    if (ledState1 == HIGH) {
      ledState1 = LOW;
    }
    else {
      ledState1 = HIGH;
    }
    digitalWrite(LED_1_PIN, ledState1);
  }  

  // task 2
  if(currentTime - previousTimeLed2 > timeIntervalLed2) {
    previousTimeLed2 = currentTime;
    if (ledState2 == HIGH) {
      ledState2 = LOW;
    }
    else {
      ledState2 = HIGH;
    }
    digitalWrite(LED_2_PIN, ledState2);
  }  

  // task 3
  if(currentTime - previousTimeLed3 > timeIntervalLed3) {
    previousTimeLed3 = currentTime;
    if (ledState3 == HIGH) {
      ledState3 = LOW;
    }
    else {
      ledState3 = HIGH;
    }
    digitalWrite(LED_3_PIN, ledState3);
  }  

  // task 4
  if(currentTime - previousTimeLed4 > timeIntervalLed4) {
    previousTimeLed4 = currentTime;
    if (ledState4 == HIGH) {
      ledState4 = LOW;
    }
    else {
      ledState4 = HIGH;
    }
    digitalWrite(LED_4_PIN, ledState4);
  }  
  
  // task 5
  if(currentTime - previousTimeLed5 > timeIntervalLed5) {
    previousTimeLed5 = currentTime;
    if (ledState5 == HIGH) {
      ledState5 = LOW;
    }
    else {
      ledState5 = HIGH;
    }
    digitalWrite(LED_5_PIN, ledState5);
  }  

  // task 6
  if(currentTime - previousTimeLed6 > timeIntervalLed6) {
    previousTimeLed6 = currentTime;
    if (ledState6 == HIGH) {
      ledState6 = LOW;
    }
    else {
      ledState6 = HIGH;
    }
    digitalWrite(LED_6_PIN, ledState6);
  }  


}
