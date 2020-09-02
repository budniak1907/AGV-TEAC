const int motorL1 = 3; //velocidade motor 1 - de 0 a 255
const int motorR2 = 4; //velocidade motor 2 - de 0 a 255
const int motorR3 = 5;
const int motorL4 = 6;
const int dirL1 = 7; //direcao do motor 1 - HIGH ou LOW
const int dirR2 = 8; //direcao do motor 2 - HIGH ou LOW
const int dirR3 = 9;
const int dirL4 = 10;
int SENSOR1, SENSOR2, SENSOR3;
int leftOffset = 0, rightOffset = 0, centre = 0;
int threshold = 5;

void setup() {
  pinMode(motorL1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorR3, OUTPUT);
  pinMode(motorL4, OUTPUT);
  pinMode(dirL1, OUTPUT);
  pinMode(dirR2, OUTPUT);
  pinMode(dirR3, OUTPUT);
  pinMode(dirL4, OUTPUT);
  calibrate();
  delay(3000);
}

void goFoward(){
  digitalWrite(dirL1, HIGH); //SENTIDO DE ROTACAO
  digitalWrite(dirL4, HIGH);
  digitalWrite(dirR2, LOW);
  digitalWrite(dirR3, LOW);
  analogWrite(motorL1, 200); //VELOCIDADE
  analogWrite(motorR2, 200);
  analogWrite(motorR3, 200); 
  analogWrite(motorL4, 200);
}
void goBack(){
  digitalWrite(dirL1, LOW); //SENTIDO DE ROTACAO
  digitalWrite(dirL4, LOW);
  digitalWrite(dirR2, HIGH);
  digitalWrite(dirR3, HIGH);
  analogWrite(motorL1, 200); //VELOCIDADE
  analogWrite(motorR2, 200);
  analogWrite(motorR3, 200); 
  analogWrite(motorL4, 200);
}
void goRight(){
  digitalWrite(dirL1, HIGH); //SENTIDO DE ROTACAO
  digitalWrite(dirL4, HIGH);
  digitalWrite(dirR2, LOW);
  digitalWrite(dirR3, LOW);
  analogWrite(motorL1, 250); //VELOCIDADE
  analogWrite(motorR2, 150);
  analogWrite(motorR3, 150); 
  analogWrite(motorL4, 250);
}
void goLeft(){
  digitalWrite(dirL1, HIGH); //SENTIDO DE ROTACAO
  digitalWrite(dirL4, HIGH);
  digitalWrite(dirR2, LOW);
  digitalWrite(dirR3, LOW);
  analogWrite(motorL1, 150); //VELOCIDADE
  analogWrite(motorR2, 250);
  analogWrite(motorR3, 250); 
  analogWrite(motorL4, 150);
}
//Rotina de calibracao do sensor
void calibrate()
{
 for (int x=0; x<10; x++) //Executa 10 vezes para obter uma media
 {
   delay(100);
   SENSOR1 = analogRead(0);
   SENSOR2 = analogRead(1);
   SENSOR3 = analogRead(2);
   leftOffset = leftOffset + SENSOR1;
   centre = centre + SENSOR2;
   rightOffset = rightOffset + SENSOR3;
   delay(100);
 }
 //obtem a media para cada sensor
 leftOffset = leftOffset /10;
 rightOffset = rightOffset /10;
 centre = centre / 10;
 //calcula os deslocamentos para os sensores esquerdo e direito
 leftOffset = centre - leftOffset;
 rightOffset = centre - rightOffset;
}
void loop() {
  goFoward();
  //le os sensores e adiciona os deslocamentos
  SENSOR1 = analogRead(0) + leftOffset;
  SENSOR2 = analogRead(1);
  SENSOR3 = analogRead(2) + rightOffset;
  //Se SENSOR1 for maior do que o sensor do centro + limiar,
// vire para a direita
 if (SENSOR1 > SENSOR2+threshold)
  {
    goRight();
  }
 
  //Se SENSOR3 for maior do que o sensor do centro + limiar,
// vire para a esquerda
  if (SENSOR3 > (SENSOR2+threshold))
  {
    goLeft();
  }
}
