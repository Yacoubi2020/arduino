int INT=2;
int led=7;
volatile bool bascule=false;
volatile unsigned long button_time = 0;
volatile unsigned long last_button_time = 0;
int debounce = 250; // debounce latency in ms
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(INT,INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(INT),inverse,CHANGE);
   i_c();
}
void loop(){
digitalWrite(led,bascule);
}
void i_c(){
attachInterrupt(digitalPinToInterrupt(INT),inverse,  CHANGE);

}
void inverse(){
   bascule =!bascule;
   button_time=millis();
  if(button_time-last_button_time>debounce)
  {
    last_button_time=millis();
 }
