#include <ShiftOutMega.h>

int latchPin = 12;  //Pino 12 conectado ao pino 12 do 74HC595 (Latch).
int dataPin = 13;  //Pino 13 conectado ao pino 14 do 74HC595 (Data).
int clockPin = 11; //Pino 11 conectado ao pino 11 do 74HC595 (Clock).
int n = 1;

ShiftOutMega mega(latchPin, dataPin, clockPin, n); 

void setup() {

}

void loop() {
  shiftOut(dataPin,clockPin, LSBFIRST, 0b10101010);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  delay(500);
  shiftOut(dataPin,clockPin, LSBFIRST, 0b01010101);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  delay(500);
}
