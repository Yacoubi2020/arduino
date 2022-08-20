int INT=2;
int led=7;
volatile bool bascule=false;
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(INT,INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(INT),inverse,CHANGE);
   i_c();
}
void loop(){
//digitalWrite(led,bascule);
}
void i_c(){
attachInterrupt(digitalPinToInterrupt(INT),inverse,  CHANGE);

}
void inverse(){
   bascule =!bascule;
  if(bascule){
    digitalWrite(led,HIGH);}
  else
    digitalWrite(led,LOW);}
