#include <EEPROM.h>

const int LM35 = 0;

float temperatura = 0;
int temp;
int deci;
int ADClido = 0;

void setup(){
  Serial.begin(9600);
  analogReference(INTERNAL1V1);
}

int i = 0;
void loop(){
  
  while(i < 40){
    ADClido = analogRead(LM35);
    temperatura = ADClido * 0.1075268817;
    temp = temperatura;
    EEPROM.write(i, temp);
    i++;
    delay(4);
    deci = 100 * (temperatura - temp) + 0.5;
    EEPROM.write(i, deci);
    i++;
    delay(4);
    delay(200);
  }
  if(i == 40){
    Serial.println("Fim escrita");
    i++;
  }
  
}
