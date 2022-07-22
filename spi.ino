# include <SPI.h>
char str[50];
volatile byte i;
volatile bool pin;

void setup()
 {
  Serial.begin (9600);   // set baud rate to 115200 for usart
  Serial.println("Hello I'm SPI UNO_SLAVE");
  //pinMode(12, OUTPUT); // have to send on Master in so it set as output
  SPCR |=0b11000000; // turn on SPI in slave mode
  i = 0; // buffer empty
  pin = false;
  //SPI.attachInterrupt();     // turn on interrupt
}

void loop(){
  if (pin)
    {
    
   Serial.println(str); //print the array on serial monitor
    }
    
    delay(1000);
}

// Interrupt function
ISR (SPI_STC_vect) 
{
 char c = SPDR;        // read byte from SPI Data Register
  if (i < sizeof(str)) {
    str [i++] = c; // save data in the next index in the array buff
    
      if (!SPSR & 0x7F) 
         pin = true;
  }
}