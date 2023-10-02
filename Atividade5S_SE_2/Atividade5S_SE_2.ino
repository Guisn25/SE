#include <EEPROM.h>

float temperatura;
int temp;
float deci;

void setup(){
  Serial.begin(9600);
  analogReference(INTERNAL1V1);
}

int i = 0;
void loop(){
  
  while(i < 40){
    temp = EEPROM.read(i);
    i++;
    deci = EEPROM.read(i);
    temperatura = temp + (deci/100);
    i++;
    Serial.print("Temperatura = ");
    Serial.print(temperatura);
    Serial.println(" *C");
  }
  if(i == 40){
    Serial.println("Fim leitura");
    i++;
  }
}
