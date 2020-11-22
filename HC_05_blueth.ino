//Mohammed yacoubi
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial myserial(2,3); //myserial(TX,RX)
Servo myservo;
int x = 7 ; 
void setup() {
 myserial.begin(9600);
 Serial.begin(9600);
 pinMode(x, OUTPUT); 
  myservo.attach(x);
}

void loop() {
  if(myserial.available()>0) 
//Obtenez le nombre d'octets disponibles pour la lecture à partir du port série
    {
    char c=myserial.read();//read l'octet
    Serial.print(c);
    switch(c){
    case 'A': // s'il  envoyé A donc le servo motor tours 90°
     myservo.write(90);
     break;
     case 'b':  // s'il encoyé b donc le servo motor tours 180°
      myservo.write(180);
     break;
     default: // else le servo il vas tourner 0°
     myservo.write(0);
   
   }
  }}
 
 
 
 
 
 
 
 
 
 /*if (myserial.available())
 {

  if (myserial.read() == 'A' )
  {
    digitalWrite(x , HIGH);
    }
    else if(myserial.read() == 'b' ) {
      digitalWrite(x , LOW) ; 
      }
  }

}*/
