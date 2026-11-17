/*******************************************************
 *  Project  : Line Follower (Analog IR Sensor Custom)
 *  Board    : Arduino Nano
 *  Driver   : L298N / L293D
 *******************************************************/

// ================= PIN KONFIGURASI ================= //
#define IN1       8
#define IN2       7
#define ENABLE_1  9
#define IN3       10
#define IN4       6
#define ENABLE_3  5

// Sensor analog (LED + Fotodioda)
#define SENSOR1   A0   // kiri
#define SENSOR2   A1
#define SENSOR3   A2   // tengah
#define SENSOR4   A3
#define SENSOR5   A4   // kanan

// Threshold (kalibrasi sesuai kondisi lintasan)
int thresholdValue = 500;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENABLE_1, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENABLE_3, OUTPUT);

  Serial.begin(9600);
  Serial.println("Line Follower (Analog LED + Photodiode)");
}

void loop() {

  // Baca nilai analog 0–1023
  int nilai1 = analogRead(SENSOR1);
  int nilai2 = analogRead(SENSOR2);
  int nilai3 = analogRead(SENSOR3);
  int nilai4 = analogRead(SENSOR4);
  int nilai5 = analogRead(SENSOR5);

  // Deteksi garis: nilai lebih kecil → lebih gelap → garis hitam
  bool detect1 = (nilai1 < thresholdValue);
  bool detect2 = (nilai2 < thresholdValue);
  bool detect3 = (nilai3 < thresholdValue);
  bool detect4 = (nilai4 < thresholdValue);
  bool detect5 = (nilai5 < thresholdValue);

  // Debug nilai sensor
  Serial.print(nilai1); Serial.print(" ");
  Serial.print(nilai2); Serial.print(" ");
  Serial.print(nilai3); Serial.print(" ");
  Serial.print(nilai4); Serial.print(" ");
  Serial.println(nilai5);

  // ================= LOGIKA LINE FOLLOWER ================= //

  // Garis lurus → sensor tengah aktif
  /* if (detect3 || (detect2 && detect3 && detect4)) {
    maju();
  }
  // Belok kanan → garis terdeteksi kiri
  else if (detect1 && detect2) {
    kanan();
  }
  // Belok kiri → garis terdeteksi kanan
  else if (detect4 && detect5) {
    kiri();
  }
  // Tidak terdeteksi → berhenti / cari garis
  else {
    berhenti();
  }
*/
if (detect2 || detect3 || detect4 ){
  maju();
}
if (detect2 || detect4 ){
  maju();
}
if (detect3 ){
  maju();
}else if (detect1 || detect2){
  kiri();
}
else if (detect1){
  kiri();
}
else if ( detect4 || detect5){
  kanan();
}
else if ( detect5){
  kanan();
}
else {
  berhenti();
}
}

// ================= Fungsi Gerak ================= //
void maju() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENABLE_1, 100);
  analogWrite(ENABLE_3, 150);
}

void mundur() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENABLE_1, 100);
  analogWrite(ENABLE_3, 180);
}

void kiri() {
  digitalWrite(IN1, LOW);   // kiri mundur
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);    // kanan maju
  digitalWrite(IN4, HIGH);
  analogWrite(ENABLE_1, 0);
  analogWrite(ENABLE_3, 160);
}

void kanan() {
  digitalWrite(IN1, LOW);    // kiri maju
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);   // kanan mundur
  digitalWrite(IN4, LOW);
  analogWrite(ENABLE_1, 100);
  analogWrite(ENABLE_3, 0);
}

void berhenti() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENABLE_1, 0);
  analogWrite(ENABLE_3, 0);
}
