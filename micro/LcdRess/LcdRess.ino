#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

void setup() {
  lcd.begin(16,2);  
  lcd.print("Barulho.:");
}

void loop() {
  lcd.setCursor(0,9);
  lcd.println(analogRead(A0));
  delay(500);
}
