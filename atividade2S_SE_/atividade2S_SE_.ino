const int ledPin1 = 11;
const int ledPin2 = 12;
const int ledPin3 = 13;
const int Botao1 = 2;
const int Botao2 = 3;
const int Botao3 = 4;
int EstadoBotao1 = 0;
int EstadoBotao2 = 0;
int EstadoBotao3 = 0;

int i;
unsigned long tempo;

int senha[3] = {1,2,3};
int tentativa[3];
bool chute;

void setup(){
  pinMode(Botao1, INPUT);
  pinMode(Botao2, INPUT);
  pinMode(Botao3, INPUT);
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop(){

  i=0;
  do{
    EstadoBotao1 = digitalRead(Botao1);
    EstadoBotao2 = digitalRead(Botao2);
    EstadoBotao3 = digitalRead(Botao3);
    
    if(EstadoBotao1 == HIGH){
      tentativa[i] = 1;
      i++;
      delay(200);
    }
    if(EstadoBotao2 == HIGH){
      tentativa[i] = 2;
      i++;
      delay(200);
    }
    if(EstadoBotao3 == HIGH){
      tentativa[i] = 3;
      i++;
      delay(200);
    }
  }while(i<3);
  
  chute = true;
  for(int j=0;j<3;j++){
    if(tentativa[j] != senha[j]){
      chute = false;  
    }
  }

  if(chute == true){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    delay(3000);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }else{
    tempo = millis();
    while(millis() - tempo < 3000){
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(500);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(500);
    } 
  }
} 
