/*int val;
void setup() {
  // put your setup code here, to run once:
for (int i=2;i<5;i++){
  pinMode(i,OUTPUT);
}
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


   analogWrite(4,255);
    analogWrite(3,0);
    analogWrite(2,0);
    delay(1);
  
Serial.println(val,DEC);}
*/
int red_light_pin= 4;
int green_light_pin = 3;
int blue_light_pin = 2;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
void loop() {
  
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,HIGH);
 digitalWrite(2,HIGH);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
   
  
  /*analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);*/
}
