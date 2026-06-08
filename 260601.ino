#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);

void setup() {
  lcd.begin(16,2);
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0,1);

  if(Serial.available()){
    char a = Serial.read();
    if(a=='1')
      lcd.print("#1 Pushed");
    if(a=='2')
      lcd.print("#2 Pushed");
  }
}
