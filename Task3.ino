int enA = 3;
int in1 = 6;
int in2 = 5;
int enB = 9;
int in3 = 7;
int in4 = 8;
void setup()
{
  for(byte i=3;i<=9;i++) pinMode(i, OUTPUT);
  stopMotors();
  Serial.begin(9600);  
}
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}
void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   analogWrite(enA, 255);
  analogWrite(enB, 255);
}
void moveLeft() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(enA, 255);
  analogWrite(enB, 0);
}
void moveRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 0);
  analogWrite(enB, 255);
}
void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
void loop()
{
 char x=Serial.read();
 for(byte i=0;i<4&&x!=-1;i++)digitalWrite(i+2,x&1<<1);
  switch(x){
    case 'A' :
     moveForward();
     break;
    case 'B' :
   moveBackward();
    break;
    case 'C' :
   moveLeft();
    break;
    case 'L' :
   moveRight();
    break;
    case 'P' :
stopMotors();
    break;
  }
}


