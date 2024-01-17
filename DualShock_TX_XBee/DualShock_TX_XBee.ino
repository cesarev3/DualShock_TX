
/*
 *************************************************************
 ** Programa de transmissao de comandos Via XBee - Game Pad **
 **             Autor Magneto - Setembro 2016               **
 *************************************************************
 */

// Pinagem do Arduino
const int button0 = 4;
const int button1 = 5;
const int button2 = 6;
const int button3 = 7;
const int button4 = 8;
const int button5 = 9;
const int button6 = 3;
const int button7 = 10;
const int button8 = 11;
const int button9 = 12;
const int joy1 = A0;
const int joy2 = A1;
const int joy3 = A2;
const int joy4 = A3;

// BotoesFrontais
int frontTopLeft;
int frontBotLeft;
int frontTopRight;
int frontBotRight;

// BotoesSuperiores
int upperLeft;
int upperRight;
int upperTop;
int upperDown;

// Botoes do Joystick
int joyBLeft;
int joyBRight;

// Joysticks Left side
int j1LeftRight;
int j2UpDown;

// Joysticks Right side
int j3LeftRight;
int j4UpDown;

void setup()
{

  // definicao da comunicacao serial
  Serial.begin(9600);

  // definicao dos pinos digitais como entrada
  pinMode (button0, INPUT);
  pinMode (button1, INPUT);
  pinMode (button2, INPUT);
  pinMode (button3, INPUT);
  pinMode (button4, INPUT);
  pinMode (button5, INPUT);
  pinMode (button6, INPUT);
  pinMode (button7, INPUT);
  pinMode (button8, INPUT);
  pinMode (button9, INPUT);
}

void loop()
{

  // carga do conteudo das entradas nas variaveis
  joyBLeft = digitalRead(button0); // botao do joystick da esquerda
  joyBRight = digitalRead(button1); // botao do joystick da direita
  frontTopLeft = digitalRead(button2); // botao frontal superior esquerdo
  frontBotLeft = digitalRead(button3); // botao frontal inferior esquerdo
  frontTopRight = digitalRead(button4); // botao frontal superior direito
  frontBotRight = digitalRead(button5); // botao frontal inferior direito
  upperLeft = digitalRead(button6); // botao superior esquerdo
  upperRight = digitalRead(button7); // botao superior direito
  upperTop = digitalRead(button8); // botao superior para cima
  upperDown = digitalRead(button9); // botao superior para baixo
  j1LeftRight = analogRead(joy1); // Joystick da esquerda
  j2UpDown = analogRead(joy2);  // Joystick da esquerda
  j3LeftRight = analogRead(joy3); // Joystick da direita
  j4UpDown = analogRead(joy4); // joystick da direita

  /* Definindo os valores dos joysticks e botoes na tabela ASCII
   j1LeftRight = 8 a 67
   j2UpDown = 68 a 127 
   j3LeftRight = 128 a 187
   j4UpDown = 188 a 247
   joyBLeft = 1 
   joyBRight = 2 
   frontTopLeft = 3
   frontBotLeft = 4
   frontTopRight = 5 
   frontBotRight = 6
   upperLeft = 248;
   upperRight = 249;
   upperTop = 250;
   upperDown = 251;
   */

  // Remapeamento para leitura analogica
  j1LeftRight = map(j1LeftRight, 0, 1023, 8, 67);
  j2UpDown = map(j2UpDown, 0, 1023, 68, 127);
  j3LeftRight = map(j3LeftRight, 0, 1023, 128, 187);
  j4UpDown = map(j4UpDown, 0, 1023, 188, 247);

  // Transferindo dados para a serial

  // Joystick 1
  Serial.write(j1LeftRight);
  delay(50);
  Serial.write(j2UpDown);
  delay(50);

  // Joystick 2
  Serial.write(j3LeftRight);
  delay(50);
  Serial.write(j4UpDown);
  delay(50);

  // Botoes 
  if(joyBLeft == HIGH) {
    Serial.write(1);
    delay(50);
  }
  if(joyBRight == HIGH) {
    Serial.write(2);
    delay(50);
  }
  if(frontTopLeft == HIGH) {
    Serial.write(3);
    delay(50);
  }
  if(frontBotLeft == HIGH) {
    Serial.write(4);
    delay(50);
  }
  if(frontTopRight == HIGH) {
    Serial.write(5);
    delay(50);
  }
  if(frontBotRight == HIGH) {
    Serial.write(6);
    delay(50);
  }
  if(upperLeft == HIGH) {
    Serial.write(248);
    delay(50);
  }
  if(upperRight == HIGH) {
    Serial.write(249);
    delay(50);
  }
  if(upperTop == HIGH) {
    Serial.write(250);
    delay(50);
  }
  if(upperDown == HIGH) {
    Serial.write(251);
    delay(50);
  }

  // Informacao para Debug via Monitor Serial
  //Serial.print("Botao Joystick esquerdo ");
  //Serial.println(joyBLeft);
  //Serial.print("Botao Joystick direito ");
  //Serial.println(joyBRight);
  //Serial.print("Botao Frontal superior esquerdo ");
  //Serial.println(frontTopLeft);
  //Serial.print("Botao Frontal inferior esquerdo ");
  //Serial.println(frontBotLeft);
  //Serial.print("Botao Frontal superior direito ");
  //Serial.println(frontTopRight);
  //Serial.print("Botao Frontal inferior direito ");
  //Serial.println(frontBotRight);
  //Serial.print("Joystick 1 direita-esquerda ");
  //Serial.println(j1LeftRight);
  //Serial.print("Joystick 1 acima-abaixo ");
  //Serial.println(j2UpDown);
  //Serial.print("Joystick 2 direita-esquerda ");
  //Serial.println(j3LeftRight);
  //Serial.print("Joystick 2 acima-abaixo ");
  //Serial.println(j4UpDown);
  //Serial.print("Botao superior esquerda ");
  //Serial.println(upperLeft);
  //Serial.print("Botao superior direito ");
  //Serial.println(upperRight);
  //Serial.print("Botao superior acima ");
  //Serial.println(upperTop);
  //Serial.print("Botao superior abaixo ");
  //Serial.println(upperDown);
  //Serial.println(" ");
  //delay(500);

}

/*
 *****************************
 **  Limites dos Joysticks  **
 **  J1 Left: 8             **
 **  J1 Center: 36          **
 **  J1 Right: 67           **
 **                         **
 **  J2 Up: 68              **
 **  J2 Center: 98          **
 **  J2 Down: 127           **
 **                         **
 **  J3 Left: 128           **
 **  J3 Center: 157         **
 **  J3 Right: 187          **
 **                         **
 **  J4 Up: 188             **
 **  J4 Center: 217         **
 **  J4 Dowm: 247           **
 *****************************
 */


















