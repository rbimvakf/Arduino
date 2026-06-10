#include <Stepper.h>

Stepper Stepper(2048, 11, 9, 10, 8);

void setup() {
  Serial.begin(9600);
  Stepper.setSpeed(10);
  Serial.println("각도를 입력하시오.");
}

void loop() {
  if(Serial.available()) {
    int degree = Serial.parseInt() * 2048 / 360;
    Stepper.step(degree);
  }
}
