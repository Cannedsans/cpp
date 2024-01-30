#include <ShiftOutMega.h> //Inclui a bilioteca ShiftOutMega.h
int number;
//Variáveis de uso dos registradores 74HC595
int latchPin = 12;  //Pino 12 conectado ao pino 12 do 74HC595 (Latch).
int dataPin = 13;  //Pino 13 conectado ao pino 14 do 74HC595 (Data).
int clockPin = 11; //Pino 11 conectado ao pino 11 do 74HC595 (Clock).

//Quantidade de registradores (74HC595). Para cada registrador, mais 8 saídas.
int qtdRegistradores = 1;

ShiftOutMega mega(latchPin, dataPin, clockPin, qtdRegistradores); //Inicia a biblioteca passando os parametros de uso.


void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  n0();
  delay (1000);
  n1();
  delay (1000);
  n2();
  delay (1000);
  n3();
  delay (1000);
  n4();
  delay (1000);
  n5();
  delay (1000);
  n6();
  delay (1000);
  n7();
  delay (1000);
  n8();
  delay (1000);
  n9();
  delay (1000);
}

void n1(){
  shiftOut(dataPin,clockPin, LSBFIRST, 0b01100000);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  }
void n2(){
  shiftOut(dataPin,clockPin, LSBFIRST, 0b11011010);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  }
void n3(){
  shiftOut(dataPin,clockPin, LSBFIRST, 0b11110010);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
}
void n4(){
  shiftOut(dataPin,clockPin, LSBFIRST, 0b01100110);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  }
void n5(){
  shiftOut(dataPin,clockPin, LSBFIRST, 0b10110110);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  }
void n6(){
  shiftOut(dataPin,clockPin, LSBFIRST, 0b11111010);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  }
void n7(){
  shiftOut(dataPin,clockPin, LSBFIRST, 0b11100010);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  }
void n8(){
  shiftOut(dataPin,clockPin, LSBFIRST, 0b11111110);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  }
void n9(){
  shiftOut(dataPin,clockPin, LSBFIRST, 0b11110110);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  }
void n0(){
  shiftOut(dataPin,clockPin, LSBFIRST, 0b11111100);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  }
