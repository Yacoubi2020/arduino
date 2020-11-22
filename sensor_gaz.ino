int sensorGas=A5;
int d;
int led=13;
int buzze=12;
void setup() {
 pinMode(sensorGas,INPUT);
 pinMode(led,OUTPUT);
 pinMode(buzze,OUTPUT);
 Serial.begin(9600);

}

void loop() {
  d=analogRead(sensorGas);
  Serial.println(d);

  if (d!=0){
    digitalWrite(led,HIGH);
    tone(buzze,50,500);
  }
  else 
  digitalWrite(led,HIGH);
    noTone(buzze);
}
