//#include <Key.h>
#include <Keypad.h>
const byte ROWs=4;
const byte cols=4;

char v[ROWs][cols]={{'1','2','3','A'},{'4','5','6','B'},
{'7','8','9','C'},{'*','0','#','D'}};

byte rowPins[ROWs]={3,4,5,6};
byte colPins[cols]={7,8,9,10};

Keypad custoKeypad=Keypad(makeKeymap(v),rowPins,colPins,ROWs,cols);
int led=13;
char custokey;
void setup(){
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
void loop(){
   custokey=custoKeypad.getKey();
   if ( custokey)
   Serial.println(custokey);
   switch(custokey)
   {
    case '1':
    digitalWrite(13,HIGH);
    break;
    case '2':
    digitalWrite(13,LOW);
    break;
}}
