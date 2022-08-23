#include <IRremote.h> // include the IRremote library
#define RECEIVER_PIN 8 // define the IR receiver pin
enum led{
  BLUE,
  RED,
  GREEN
};
unsigned long timemilis=0;
unsigned long timeres=0;
unsigned long delayTime=2000;
byte activeChannel = RED; // Start with RED as the active channel
boolean state=true;
byte c[]={6,5,9};
byte val[3]={12,13,40};
IRrecv receiver(RECEIVER_PIN); // create a receiver object of the IRrecv class
decode_results results; // create a results object of the decode_results class
void setup()
{
   Serial.begin(9600); // begin serial communication with a baud rate of 9600
   for(int i=0;i<3;i++){
    pinMode(c[i],OUTPUT);
    analogWrite(c[i],0);
   }
   pinMode(2,INPUT_PULLUP);

   receiver.enableIRIn(); // enable the receiver
   receiver.blink13(true); // enable blinking of the built-in LED when an IR signal is received
   SREG |=0X80;
   EIMSK|=0X01;
   EICRA|=0X03;
}
void loop() {
  sei();
  if(receiver.decode(&results)) { // decode the received signal and store it in results
  //Serial.println(results.value,HEX);
  switch(results.value){
  
  case 0XFF6897:  //BLUE
 
      activeChannel=BLUE;
       break;
    case 0XFF9867  ://RED
 
       activeChannel=RED;
       break;
     case 0XFFB04F:  //GREEN
 
        activeChannel=GREEN;
        break;
  
 case 0XFFA857 : // +
       //analogWrite(6,coun);
       val[activeChannel]++;
    break;   
 
 case 0XFFE01F  : // +
       //analogWrite(6,coun);
      val[activeChannel]--;
      break;   

} 
 receiver.resume();
timemilis=millis();
if( timemilis-timeres>delayTime){


if(1){
  for(int i=0;i<3;i++){

  analogWrite(c[i],val[i]);
  Serial.println(val[i]);}
  
}
timeres=millis();
}


}}
ISR(INT0_vect){
  for(int i=0;i<3;i++)

  analogWrite(c[i],0);
  
  
}
