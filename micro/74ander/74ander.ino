#include <ShiftOutMega.h>

int latchPin = 12;  //Pino 12 conectado ao pino 12 do 74HC595 (Latch).
int dataPin = 13;  //Pino 13 conectado ao pino 14 do 74HC595 (Data).
int clockPin = 11; //Pino 11 conectado ao pino 11 do 74HC595 (Clock).
int n = 1;
ShiftOutMega mega(latchPin, dataPin, clockPin, 1);
void setup() {
  
}
void loop() {
  mega.shiftWrite(n,HIGH);
  delay(500);
  mega.shiftWrite(n,LOW);
  n++;
  if (n > 8){
    n = 0;
    }
}
