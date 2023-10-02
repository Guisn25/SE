const int BotaoON = 2;
const int Sensor = 13;
const int LM35 = 0;

int estadoBotao = 0;
bool estadoSensor = false;

//unsigned long tempoDebounce = 0;
//unsigned long debounceDelay = 50;
unsigned long tempo = 0;

float temperatura = 0;
int ADClido = 0;

float menor;
float maior;
float media;

/*
  int debouncedRead(int Botao) {
  int estadoBotaoUltimo = LOW;
  int leitura = digitalRead(Botao);

  while((millis() - tempoDebounce) < debounceDelay){
    if(leitura != estadoBotaoUltimo) {
      tempoDebounce = millis();
    }
    if(leitura != estadoBotao){
      estadoBotao = leitura;
    }
    estadoBotaoUltimo = estadoBotao;
  }
  return estadoBotao;
  }
*/

void setup(){
  Serial.begin(9600);
  analogReference(INTERNAL1V1);
  pinMode(BotaoON, INPUT);
  pinMode(Sensor, OUTPUT);
}

void loop(){
  maior = -1;
  menor = 150;
  media = 0;
  
  int i=0;
  do{
    estadoBotao = digitalRead(BotaoON);
    
    if(estadoBotao == HIGH){
      estadoSensor = !estadoSensor;
      delay(200);
    }
    if(estadoSensor == true && millis()-tempo > 500){
      digitalWrite(Sensor, HIGH);
      ADClido = analogRead(LM35);
      temperatura = ADClido * 0.1075268817;
      if(temperatura > maior){
        maior = temperatura;
      }
      if(temperatura < menor){
        menor = temperatura;
      }
      media += temperatura;
      i++;
      Serial.print("Temperatura = ");
      Serial.print(temperatura);
      Serial.println(" *C");
      
      tempo = millis();
    }
    
  }while(estadoSensor == true);
  
  if(i>0){
    media = media/i;
    Serial.print("media = ");
    Serial.print(media);
    Serial.println(" *C");
    Serial.print("maior = ");
    Serial.print(maior);
    Serial.println(" *C");
    Serial.print("menor = ");
    Serial.print(menor);
    Serial.println(" *C");
  }
 
 digitalWrite(Sensor, LOW);
}
