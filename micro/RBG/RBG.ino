boolean r = false,g = false,b = false;
void setup() {
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  if (digitalRead(2) == 1){
    b = !b;
    }
  if (digitalRead(3) == 1){
    g = !g;
    }
  if (digitalRead(4) == 1){
    r = !r;
    }
  digitalWrite(8,b);
  digitalWrite(9,g);
  digitalWrite(10,r);
}
