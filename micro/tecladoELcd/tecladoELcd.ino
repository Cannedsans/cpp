#include <Keypad.h>

#include <LiquidCrystal.h>

const byte l = 4;
const byte c = 4;

const char chars [c][l] = {
  {'3','2','1','a'},
  {'6','5','4','b'},
  {'9','8','7','c'},
  {'#','0','*','d'}
  };
const byte pl[l] = {A0,A1,A2,A3};
const byte pc[c] = {2,3,4,5};

Keypad teclado = Keypad(makeKeymap(chars), pl,pc, l,c);

LiquidCrystal lcd(8,9,10,11,12,13);

void setup() {
  lcd.begin(16,2);
}

void loop() {
  char tecla = teclado.getKey();
  if (tecla){
    lcd.print(tecla);
    }
   delay(1000); 
   lcd.clear();
}
