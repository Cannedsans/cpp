boolean luz = false;
void setup() {
  pinMode(7,OUTPUT);
}

void loop() {
  if (analogRead(A0) >= 100){
    luz = !luz;
    }
   digitalWrite(7, luz); 
}
