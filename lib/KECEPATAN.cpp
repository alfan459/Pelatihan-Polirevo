#include "KECEPATAN.h"
#include "Arduino.h"
#define pwm1 5
#define pwm2 6
#define ena 3
#define enb 4

int tombol_up = 8,
    tombol_down = 9,
    kecepatan = 0, 
    tambah, kurang;

//constructor
KECEPATAN::KECEPATAN(){
    pinMode(tombol_up, INPUT);
    pinMode(tombol_down, INPUT);
    pinMode(pwm1, OUTPUT);
    pinMode(pwm2, OUTPUT);
    pinMode(ena, OUTPUT);
    pinMode(enb, OUTPUT);
    Serial.begin(9600);
}

//destructor
KECEPATAN::~KECEPATAN(){}

//class class yang nanti akan dipanggil
void KECEPATAN::pengatur_kecepatan(){
    tambah = digitalRead(tombol_up);
    kurang = digitalRead(tombol_down);

    digitalWrite(pwm1, HIGH);
    digitalWrite(pwm2, LOW);

  if(tambah == LOW){
    delay(300);
    kecepatan = kecepatan + 100;
  }
  else if(kurang == LOW){
    delay(300);
    kecepatan = kecepatan - 100;
  }
  else if(kecepatan >=255){
    kecepatan = 255;
  }
  else if(kecepatan < -1){
    kecepatan = 0;
  }
  else {
    kecepatan;
  }

  analogWrite(ena, kecepatan);
}

void KECEPATAN::tampilan_kecepatan(){
    Serial.println(kecepatan);
}