const int TRIG = 2;
const int ECHO = 3;
const int LED = 4;
const int BUZZER = 5;
const int distancia_obstaculo = 20;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  int distancia = calcularDistancia(TRIG,ECHO);
  /*if(distancia <= distancia_obstaculo){
      Serial.print("Com obstaculo: ");
      Serial.print(distancia);
      Serial.println("cm");
  }
  else{
      Serial.print("Sem obstaculo: ");
      Serial.print(distancia);
      Serial.println("cm");
  }*/
  Serial.print(distancia);
  Serial.println("cm");
  delay(400);
  
   if(distancia <= 150){
     digitalWrite(LED, HIGH);
     tone(BUZZER, 1000);
     delay(150);
     tone(BUZZER,750);
  }else{
    digitalWrite(LED, LOW);
    noTone(BUZZER);
  }
  delay(500);
}

int calcularDistancia(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}
