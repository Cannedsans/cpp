#include <LiquidCrystal.h>

LiquidCrystal lcd(3,4,5,6,7,8);

void setup() {
  lcd.begin(16,2);
}

void loop() {
  lcd.clear();
  lcd.print(analogRead(A0));
  delay(700);
}
