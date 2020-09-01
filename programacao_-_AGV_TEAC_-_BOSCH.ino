const int motor1 = 5; //velocidade motor 1 - de 0 a 255
const int motor2 = 6; //velocidade motor 2 - de 0 a 255
const int dir1 = 7; //direcao do motor 1 - HIGH ou LOW
const int dir2 = 8; //direcao do motor 2 - HIGH ou LOW

void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
}

void loop() {

  digitalWrite(dir1, HIGH); //SENTIDO DE ROTACAO
  digitalWrite(dir2, LOW);
  analogWrite(motor1, 200); //VELOCIDADE
  analogWrite(motor2, 200);
  
  delay(1000);
  
  analogWrite(motor1, 0);
  analogWrite(motor2, 0);
  
  delay(1000);
  
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH);
  analogWrite(motor1, 200);
  analogWrite(motor2, 200);
  
  delay(1000);

  analogWrite(motor1, 0);
  analogWrite(motor2, 0);
  
  delay(1000);
}
