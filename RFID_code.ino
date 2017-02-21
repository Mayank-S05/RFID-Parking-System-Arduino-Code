#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
#define SP_PIN 8
#include <Keypad.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 6, 5, 4, 3, 2);
LiquidCrystal lcd1(8, 7, 5, 4, 3, 2);
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

//GLOBAL VARIABLES
String code="";
const byte ROWS = 2;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
};
int keys[6][6];
int g=0;
String balance[10];
int amt[10];
unsigned long int start[10];
unsigned long int ending[10];
unsigned long int start1[10];
unsigned long int ending1[10];
int o=0;
byte rowPins[ROWS] = {A0,A1}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A3,A4,A5}; //connect to the column pinouts of the keypad
int p=0;
int q = 0;
int s=0;
int balid=0;  
String a[10]; 
String strID;  

//CODE FOR INITIAL SETUP OF ARDUINO 
void setup() 
{
  pinMode(A2,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd1.begin(16,2);
  SPI.begin();
  rfid.PCD_Init();
  digitalWrite(A2,LOW);
lcd1.clear();  
lcd1.print("NIIT University");
lcd1.setCursor(0,1);
lcd1.print("Parking System..");
}

void loop() {  
  code = "";
  strID = "";
  char mode = getmode();
   if(mode == '1')
   {
    lcd.clear();
    lcd.print("Show RFid...."); 
           
  while(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    {
   
    }
  MFRC522::PICC_Type piccType =rfid.PICC_GetType(rfid.uid.sak);
  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  } 
    for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();
  code = strID;
  readid();
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  }
  
else if (mode == '2')
{
   getkeys();      
}
else {}
}

  
