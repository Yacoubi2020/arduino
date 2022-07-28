#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include  <Wire.h>

#define SS_PIN 10
#define RST_PIN 9
#define Buzzer 5
unsigned long  time1=0;
bool flag;
int rst=0;
LiquidCrystal_I2C lcd(0x27,16,2);
MFRC522 rfid(SS_PIN,RST_PIN);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
SPI.begin();
lcd.init();
lcd.backlight();
rfid.PCD_Init();
  
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
 if (millis()-time1>=10000){
    lcd.setCursor(1,0);
    lcd.print("Bienvenue");
    time1=millis();
    rst=1;
 }
 if(millis()-time1>=5000 &&  rst==1){
  lcd.clear();
  rst=0;
 }
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
    lcd.setCursor(1,0);
    lcd.print("hello ahmed");
    delay(2000);
    lcd.clear();
    flag=true;
  }else if(UID.substring(1) == "83 10 6E 11")  //2
  { 
    Serial.println("Mohammed");
    Serial.println("Authorized access");
     lcd.setCursor(1,0);
    lcd.print("hello Mohammed ");
    delay(2000);
    lcd.clear();
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
    lcd.setCursor(1,0);
    lcd.print("ERREUR d'acees ");
    delay(2000);
    flag=false;
  }
  
  rfid.PICC_HaltA();
  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
  
}
}