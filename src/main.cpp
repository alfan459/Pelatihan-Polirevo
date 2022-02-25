//Program by alfan
//23 Februari

#include "Arduino.h"
#include "KECEPATAN.h"

KECEPATAN motor;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.pengatur_kecepatan();
  motor.tampilan_kecepatan();
}