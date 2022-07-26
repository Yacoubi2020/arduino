#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
#define Buzzer 5
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
bool flag=false;
bool flag1=false;
 
void setup() 
{
  Serial.begin(9600);
  SPI.begin();      // Initiate  SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  pinMode(Buzzer,OUTPUT);
  Serial.println("Approximate your Card to the Reader....");
}
void loop() 
{
  rfid1();
  if(flag)
  {
    tone(Buzzer,500);
    delay(100);
    noTone(Buzzer);
    flag=false;
  }
  
} 

void rfid1()
{
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
  String UID="";
  for (byte i=0;i<rfid.uid.size;i++) 
  {
     Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(rfid.uid.uidByte[i], HEX);
     UID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ")); 
     UID.concat(String(rfid.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  UID.toUpperCase();
  
  if (UID.substring(1) == "D3 CF 70 11") //change here the UID of the card/cards that you want to give access  //1
  {
    Serial.println("Ahmed");
    Serial.println("Authorized access");
    flag=true;
  }else if(UID.substring(1) == "83 10 6E 11")  //2
  { 
    Serial.println("Mohammed");
    Serial.println("Authorized access");
    flag=true;
  }else           //3 83 8D 76 0D
  {
    Serial.println(" Access denied");
    tone(Buzzer,1000);
    delay(500);
    noTone(Buzzer);
    tone(Buzzer,1000);
    delay(500);
    noTone(Buzzer);
    tone(Buzzer,1000);
    delay(500);
    noTone(Buzzer);
    flag=false;
  }
  
  rfid.PICC_HaltA();
  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
  
}
}
