#include <SPI.h>
char values[]="hello world \n";

void setup() {
  // put your setup code here, to run once:
SPI.begin();
SPI.setClockDivider(SPI_CLOCK_DIV8);
//Serial.begin(115200);
Serial.print("hzllo");

}

void loop() {
  char c ;
  digitalWrite(SS,LOW);
  for (int i=0;i<sizeof(values);i++){
    SPI.transfer(values[i]);
  }
  digitalWrite(SS,HIGH); 
  delay(1000);
  // put your main code here, to run repeatedly:

}
