char botaoPIC;
unsigned long TLED1, TLED2;
void setup(){
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  if(Serial2.available()){
    botaoPIC = Serial2.read();
  }

  if(botaoPIC == 'A'){
    digitalWrite(2, HIGH);
    TLED1 = millis();
    Serial.println("Pressionado RB5");
  }

  if(botaoPIC == 'B'){
    digitalWrite(4, HIGH);
    TLED2 = millis();
    Serial.println("Pressionado 0");
  }

  if(millis()-TLED1 > 1000){
    digitalWrite(2, LOW);
  }
  if(millis()-TLED2 > 1000){
    digitalWrite(4, LOW);
  }
  botaoPIC = ' ';
}
