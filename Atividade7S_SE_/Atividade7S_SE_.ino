#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int estadoBotaoBACK = 0;
int estadoBotaoENTER = 0;
int estadoBotaoDOWN = 0;
int estadoBotaoUP = 0;

int estadoBotao;
unsigned long tempoDebounce = 0;

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
  }while((millis() - tempoDebounce) < 50);
  
  return estadoBotao;
}

void setup(){
  lcd.begin(16, 2);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
}

int i=1;
int j;
void loop(){
  estadoBotaoENTER = debouncedRead(9);
  estadoBotaoDOWN = debouncedRead(8);
  estadoBotaoUP = debouncedRead(7);

  if(estadoBotaoENTER == LOW){
    lcd.setCursor(0,0);
    lcd.print("Opcao ");
    lcd.print(i);
    lcd.print("*");
    j = (i%5)+1;
    lcd.setCursor(0,1);
    lcd.print("Opcao ");
    lcd.print(j);
  }else{
    lcd.clear();
    do{
      estadoBotaoBACK = debouncedRead(10);
      lcd.setCursor(0,0);
      lcd.print("Escolhi a opcao ");
      lcd.setCursor(0,1);
      lcd.print(i);
      lcd.print("...");
    }while(estadoBotaoBACK == LOW);  
    lcd.clear();
  }

  if(estadoBotaoUP == HIGH){
    i = (i%5)+1;
  }
  if(estadoBotaoDOWN == HIGH){
    i = ((i+3)%5)+1;
  }
}
