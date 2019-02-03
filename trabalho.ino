#include<LiquidCrystal.h>

const int azul = 9;
const int verde = 10;
const int vermelho = 11;
int soundSensor = 7;
int cont = 0;

LiquidCrystal lcd(12,6,5,4,3,2);

void setup(){
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Bem vindo a");
//  delay(700);
  //lcd.clear();
  lcd.setCursor(2,1);
  lcd.print("Spoladorland");
  //delay(700);
  //lcd.clear();

   Serial.begin(9600);
   pinMode(vermelho, OUTPUT);
   pinMode(verde, OUTPUT);
   pinMode(azul, OUTPUT);
   pinMode(soundSensor, INPUT);
}
 
//Funções responsáveis por executar o brilho selecionado
void vermelhoFuncao(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);
}

void verdeFuncao(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);
}
void azulFuncao(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
}

void brancoFuncao(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, HIGH);
}

void amareloFuncao(){
  analogWrite(azul, 0);
  analogWrite(verde, 255);
  analogWrite(vermelho, 255);
}

void loop(){
  
  int statusSensor = digitalRead(soundSensor);
  if(statusSensor==1){
   verdeFuncao();
   delay(100); 
   cont++;
   if(cont>5&&statusSensor==1){
    azulFuncao();
    delay(50);
   }
   amareloFuncao();
   delay(30);
  }  
  else if(statusSensor==0){
    vermelhoFuncao();
    delay(30);
  }
}
