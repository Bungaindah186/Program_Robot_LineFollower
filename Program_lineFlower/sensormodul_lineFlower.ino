#define IN1 8
#define IN2 7
#define ENABLE_1 9
#define IN3 10
#define IN4 6
#define ENABLE_3 5

#define SENSOR1 13
/*#define SENSOR2 3
#define SENSOR3 2
#define SENSOR4 11
#define SENSOR5 12 */

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENABLE_1, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENABLE_3, OUTPUT);

  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(SENSOR3, INPUT);
  pinMode(SENSOR4, INPUT);
  pinMode(SENSOR5, INPUT);
}

void loop() {
  int nilai1 = digitalRead(SENSOR1);
  /*int nilai2 = digitalRead(SENSOR2);
  int nilai3 = digitalRead(SENSOR3);
  int nilai4 = digitalRead(SENSOR4);
  int nilai5 = digitalRead(SENSOR5);*/
  
  if (nilai1 = 0){
    kanan();
  }
  else {
    maju();
  }

 /* if (nilai2 == 0 && nilai3 == 0 && nilai4 == 0) {
    maju();
  } else if (nilai1 == 0 || nilai2 == 0) {
    kiri();
  } else if (nilai4 == 0 || nilai5 == 0) {
    kanan();
  } else {
    berhenti();
  }*/
}

void maju() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENABLE_1, 255);
  analogWrite(ENABLE_3, 255);
}

void kiri() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENABLE_1, 255);
  analogWrite(ENABLE_3, 255);
}

void kanan() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENABLE_1, 255);
  analogWrite(ENABLE_3, 255);
}

void berhenti() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENABLE_1, 0);
  analogWrite(ENABLE_3, 0);
}
