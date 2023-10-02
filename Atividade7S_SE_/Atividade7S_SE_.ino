#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int BotaoBACK = 10;
const int BotaoENTER = 9;
const int BotaoDOWN = 8;
const int BotaoUP = 7;

int estadoBotaoBACK = 0;
int estadoBotaoENTER = 0;
int estadoBotaoDOWN = 0;
int estadoBotaoUP = 0;

int estadoBotao;
unsigned long tempoDebounce = 0;
unsigned long debounceDelay = 200;

unsigned long tempo;

int debouncedRead(int Botao){  
  int estadoBotaoUltimo = LOW;
  int leitura = digitalRead(Botao);
  
  do{
    if(leitura != estadoBotaoUltimo) {
      tempoDebounce = millis();
    }
    if(leitura != estadoBotao) {
      estadoBotao = leitura;
    }
    estadoBotaoUltimo = estadoBotao;
  }while((millis() - tempoDebounce) < debounceDelay);
  
  return estadoBotao;
}

void setup(){
  lcd.begin(16, 2);
  pinMode(estadoBotaoBACK, INPUT);
  pinMode(estadoBotaoENTER, INPUT);
  pinMode(estadoBotaoDOWN, INPUT);
  pinMode(estadoBotaoUP, INPUT);
}

int i=1;
int j;
void loop(){
  estadoBotaoENTER = debouncedRead(BotaoENTER);
  estadoBotaoDOWN = debouncedRead(BotaoDOWN);
  estadoBotaoUP = debouncedRead(BotaoUP);

  if(estadoBotaoENTER == LOW){
    lcd.setCursor(0,0);
    lcd.print("Opcao ");
    lcd.print(i);
    lcd.print("*");
    j = (i+1)%6;
    if(j == 0){
      j=1;
    }
    lcd.setCursor(0,1);
    lcd.print("Opcao ");
    lcd.print(j);
  }else{
    lcd.clear();
    do{
      estadoBotaoBACK = debouncedRead(BotaoBACK);
      lcd.setCursor(0,0);
      lcd.print("Escolhi a opcao ");
      lcd.setCursor(0,1);
      lcd.print(i);
      lcd.print("...");
    }while(estadoBotaoBACK == LOW);  
    lcd.clear();
  }
//Essa parte ficou feia
  if(estadoBotaoUP == HIGH){
    i = (i+1)%6;
  }
  if(estadoBotaoDOWN == HIGH){
    i = (i-1)%6;
    if(i==0){
      i=5;
    }
  }
  if(i==0){
    i=1;
  }
}
