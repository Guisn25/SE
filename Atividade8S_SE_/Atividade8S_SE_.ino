#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
const int Motor = 8;

unsigned long tempo = 0;

int ValorMotor = 0;
int pwm = 0;
bool subida = true;

void setup(){
  lcd.begin(16, 2);
  pinMode(Motor, OUTPUT);
}

void loop() {
  if(millis() - tempo > 100){
    if(subida){
      ValorMotor++;
    }else{
      ValorMotor--;
    }
    if(ValorMotor%100 == 0){
      subida = !subida;
    }
    pwm = map(ValorMotor, 0, 100, 0, 255);
    analogWrite(Motor, pwm);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(ValorMotor);
    lcd.print("%");

    tempo = millis();
  }
}
