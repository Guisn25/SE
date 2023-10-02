#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int BotaoON = 7;
const int Sensor = 8;
const int LM35 = 0;

int estadoBotao = 0;
bool estadoSensor = false;
bool Novaleitura = true;

unsigned long tempo;

float temperatura = 0;
int ADClido = 0;

void setup(){
  lcd.begin(16, 2);
  pinMode(BotaoON, INPUT);
  pinMode(Sensor, OUTPUT);
  analogReference(INTERNAL1V1);
}

void loop(){
  estadoBotao = digitalRead(BotaoON);
  if(estadoBotao == HIGH){
    estadoSensor = !estadoSensor;
    delay(200);
  }
  
  if(estadoSensor == true && millis() - tempo > 1000){
    if(Novaleitura){
      digitalWrite(Sensor, HIGH);
      ADClido = analogRead(LM35);
      temperatura = ADClido * 0.1075268817;
      lcd.setCursor(0,0);
      lcd.print("Temp: ");
      lcd.print(temperatura);
      lcd.print(" *C");
      tempo = millis();
    }else{ 
      lcd.setCursor(0,1);
      lcd.print("Temp: ");
      lcd.print(temperatura);
      lcd.print(" *C");
    }
    Novaleitura = !Novaleitura;
  }
  if(estadoSensor == false){
    digitalWrite(Sensor, LOW);
  }
}
