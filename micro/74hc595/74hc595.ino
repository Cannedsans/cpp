#include <ShiftOutMega.h> //Inclui a bilioteca ShiftOutMega.h
int number;
//Variáveis de uso dos registradores 74HC595
int latchPin = 12;  //Pino 12 conectado ao pino 12 do 74HC595 (Latch).
int dataPin = 13;  //Pino 13 conectado ao pino 14 do 74HC595 (Data).
int clockPin = 11; //Pino 11 conectado ao pino 11 do 74HC595 (Clock).

//Quantidade de registradores (74HC595). Para cada registrador, mais 8 saídas.
int qtdRegistradores = 1;

ShiftOutMega mega(latchPin, dataPin, clockPin, qtdRegistradores); //Inicia a biblioteca passando os parametros de uso.

void setup(){
  Serial.begin(9600);
}

void loop(){
    while(Serial.available() > 0) { 
    number = Serial.parseInt();
    if(number>0){
    Serial.print("numero: ");
    Serial.println(number);
    
    mega.shiftWrite(number, HIGH);
    delay(2000); 
    mega.shiftWrite(number, LOW);
    }
  }
}
