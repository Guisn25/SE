const int ledPin1 = 10;
const int ledPin2 = 11;
const int ledPin3 = 12;
const int Buzzer = 13;

const int Botao1 = 2;
const int Botao2 = 3;
const int Botao3 = 4;

int EstadoBotao1 = 0;
int EstadoBotao2 = 0;
int EstadoBotao3 = 0;
int melodia[5] = {0, 0, 0, 0, 0};

unsigned long tempo = 0;
int i;
 
void setup() {
  pinMode(Botao1, INPUT);
  pinMode(Botao2, INPUT);
  pinMode(Botao3, INPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop(){
  tempo = millis();
  
  i=0;
  do{
    EstadoBotao1 = digitalRead(Botao1);
    EstadoBotao2 = digitalRead(Botao2);
    EstadoBotao3 = digitalRead(Botao3);
    if(EstadoBotao1 == HIGH) {
      digitalWrite(ledPin1, HIGH);
      melodia[i] = 100;
      i++;
      tempo = millis();
      delay(200);
      digitalWrite(ledPin1, LOW);
    }
    if(EstadoBotao2 == HIGH) {
      digitalWrite(ledPin2, HIGH);
      melodia[i] = 200;
      i++;
      tempo = millis();
      delay(200);
      digitalWrite(ledPin2, LOW);
    }
    if(EstadoBotao3 == HIGH) {
      digitalWrite(ledPin3, HIGH);
      melodia[i] = 500;
      i++;
      tempo = millis();
      delay(200);
      digitalWrite(ledPin3, LOW);
    }
  }while(millis() - tempo < 3000 && i < 5);

  for(int j=0;j<i;j++){
    tone(Buzzer, melodia[j], 500);
    delay(600);
  }
}
