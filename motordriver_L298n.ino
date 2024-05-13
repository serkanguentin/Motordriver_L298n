#include <Arduino.h>

// Enable pinleri
#define echoPin 12 //Ultrasonik sensörün echo pini Arduino'nun 12.pinine
#define trigPin 13 //Ultrasonik sensörün trig pini Arduino'nun 13.pinine tanımlandı.
long sure, uzaklik; //süre ve uzaklık diye iki değişken tanımlıyoruz.

int buzzerpin=2; 

const int enablePin1 = 9;
const int enablePin2 = 3;

// Motor 1 pinleri
const int motorPin1A = 7;
const int motorPin1B = 6;

// Motor 2 pinleri
const int motorPin2A = 4;
const int motorPin2B = 5;

void setup() {

  // Pinleri çıkış olarak ayarlayın
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  pinMode(motorPin1A, OUTPUT);
  pinMode(motorPin1B, OUTPUT);
  pinMode(motorPin2A, OUTPUT);
  pinMode(motorPin2B, OUTPUT);
}

void loop() {
  // Motor 1'i ileri yönde çalıştırın
  digitalWrite(trigPin, LOW); //sensör pasif hale getirildi
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); //Sensore ses dalgasının üretmesi için emir verildi
  delayMicroseconds(10);
   digitalWrite(trigPin, LOW); //Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi
  sure = pulseIn(echoPin, HIGH); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
  uzaklik = sure / 29.1 / 2; //ölçülen süre uzaklığa çevriliyor
  ileri();
  // 2 saniye bekleyin
  delay(500);
  dur();
  delay(500);

  if (uzaklik <=45 && uzaklik >30){
    
  
digitalWrite(buzzerpin , HIGH);
delay(50);
digitalWrite(buzzerpin , LOW);
delay(400);

  
} // Motorları durdurun
  else if (uzaklik <=30 && uzaklik >15){
digitalWrite(buzzerpin, HIGH);
delay(50); // ledin yanık kalma süresiyle buzzerin uyarı süresi standart bir süreye 150ms ye ayarlandı.
digitalWrite(buzzerpin , LOW);
delay(200);


  
} // Motorları durdurun
  if (uzaklik <=15 && uzaklik >0){
digitalWrite(buzzerpin, HIGH);
delay(50); // ledin yanık kalma süresiyle buzzerin uyarı süresi standart bir süreye 150ms ye ayarlandı.
digitalWrite(buzzerpin , LOW);
delay(100);
   
} // Motorları durdurun
 
}
void ileri(){
  analogWrite(enablePin1, 255);
  digitalWrite(motorPin1A, HIGH);
  digitalWrite(motorPin1B, LOW);

  // Motor 2'yi geri yönde çalıştırın
  analogWrite(enablePin2, 255);
  digitalWrite(motorPin2A, LOW);
  digitalWrite(motorPin2B, HIGH);
}
void dur(){
  digitalWrite(enablePin1, LOW);
  digitalWrite(enablePin2, LOW);
}