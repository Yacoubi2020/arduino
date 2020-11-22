#define pinA 2
#define pinB 3
#define pinC 4
#define pinD 5
#define pinE 6
#define pinF 7
#define pinG 8
#define D1 10
#define D2 11
#define D3 12
#define D4 13

void setup() {                
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
}

void loop() {
  //afficher sur le segment N°4
 
  digitalWrite(D1, HIGH); 
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
  //afficher le Nombre 0 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB,HIGH);   
  digitalWrite(pinC,HIGH);   
  digitalWrite(pinD,HIGH);   
  digitalWrite(pinE,HIGH);   
  digitalWrite(pinF,HIGH);   
  digitalWrite(pinG, LOW);   
  delay(1);    

  //ensuite afficher sur le segment N°3
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
   
  //afficher le nombre 2 sur cette segment
  
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB,HIGH);   
  digitalWrite(pinC,LOW);   
  digitalWrite(pinD,HIGH);   
  digitalWrite(pinE,HIGH);   
  digitalWrite(pinF,LOW);   
  digitalWrite(pinG,HIGH);   
  delay(1); 

 //afficher sur le segment N°2
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3,HIGH);
  digitalWrite(D4, HIGH);
   
  //afficher le nombre 0 sur cett segment 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB,HIGH);   
  digitalWrite(pinC,HIGH);   
  digitalWrite(pinD,HIGH);   
  digitalWrite(pinE,HIGH);   
  digitalWrite(pinF,HIGH);   
  digitalWrite(pinG, LOW);  
  delay(1);

  //afficher sur le segment N°1 
   
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH); 
  
//afficher sur cette segment le nombre 2

  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB,HIGH);   
  digitalWrite(pinC,LOW);   
  digitalWrite(pinD,HIGH);   
  digitalWrite(pinE,HIGH);   
  digitalWrite(pinF,LOW);   
  digitalWrite(pinG,HIGH);   
  delay( 1);
}
  
