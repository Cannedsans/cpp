void setup() {
  randomSeed(analogRead(0));
  pinMode (10,OUTPUT);
  pinMode (7,INPUT);
}

void loop() {
  if (!digitalRead(7)){
    tone(10,262,200); //DO
    delay(200);
  tone(10,294,300); //RE
  delay(200);
tone(10,330,300); //MI
delay(200);
tone(10,349,300); //FA
delay(300);
tone(10,349,300); //FA
delay(300);
tone(10,349,300); //FA
delay(300);
tone(10,262,100); //DO
delay(200);
tone(10,294,300); //RE
delay(200);
tone(10,262,100); //DO
delay(200);
tone(10,294,300); //RE
delay(300);
tone(10,294,300); //RE
delay(300);
tone(10,294,300); //RE
delay(300);
tone(10,262,200); //DO
delay(200);
tone(10,392,200); //SOL
delay(200);
tone(10,349,200); //FA
delay(200);
tone(10,330,300); //MI
delay(300);
tone(10,330,300); //MI
delay(300);
tone(10,330,300); //MI
delay(300);
tone(10,262,200); //DO
delay(200);
tone(10,294,300); //RE
delay(200);
tone(10,330,300); //MI
delay(200);
tone(10,349,300); //FA
delay(300);
tone(10,349,300); //FA
delay(300);
tone(10,349,300); //FA
delay(300);
    }
}
