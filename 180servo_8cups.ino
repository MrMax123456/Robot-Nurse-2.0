
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>.
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp; 
Servo servo;
Servo servoHead;
Servo servoBack;
void setup() {
  Serial.begin(9600);
  Serial.println("Waiting for card...");
  SPI.begin();  
  mfrc522.PCD_Init();     
  servo.attach(7);
  servoHead.attach(8);
  servoBack.attach(2);
  servo.write(0); 
  servoBack.write(0); 
}
void loop() {
  servoHead.write(12);
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  uidDec = 0;

  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    uidDecTemp = mfrc522.uid.uidByte[i];
    uidDec = uidDec * 256 + uidDecTemp;
  }
  Serial.println("Card UID: ");
  Serial.println(uidDec); 
  if (uidDec == 1010527759) //first metka, cup 1
  {    
    tone(5, 200, 500); 
    servo.write(45); 
    delay(5000); 
    tone(5, 500, 500); 
    servo.write(0);  
    delay(1000); 
     
  }


    if (uidDec == 1815703055) //2nd metka, cup 2
  {
    servoHead.write(54);

    delay(3000);

    tone(5, 200, 500); 
    servo.write(45); 
    delay(5000); 
    tone(5, 500, 500); 
    servo.write(0);  
    delay(1000);   

    servoHead.write(12);

  }
  
    if (uidDec == 3157945871) //3rd metka, cup 3
  {
    servoHead.write(96);

    delay(3000);

    tone(5, 200, 500); 
    servo.write(45); 
    delay(5000); 
    tone(5, 500, 500); 
    servo.write(0);  
    delay(1000);   

    servoHead.write(12);

    
   
  }

  if (uidDec == 4231687695) //4th metka, cup 4
  {
    
    servoHead.write(138);

    delay(3000);

    tone(5, 200, 500); 
    servo.write(45); 
    delay(5000); 
    tone(5, 500, 500); 
    servo.write(0);  
    delay(1000);   

    servoHead.write(12);

    

  }

    if (uidDec == 2888855055) //5th metka, cup 5
  {
    servoHead.write(180);

    delay(3000);

    tone(5, 200, 500); 
    servo.write(45); 
    delay(5000); 
    tone(5, 500, 500); 
    servo.write(0);  
    delay(1000);   

    servoHead.write(12);

  }

  if (uidDec == 3962596879) //6th metka, cup 6
  {
    servoHead.write(39);

    delay(3000);

    tone(5, 200, 500); 
    servoBack.write(45); 
    delay(5000); 
    tone(5, 500, 500); 
    servoBack.write(0);  
    delay(1000);   

    servoHead.write(12);

  }

    if (uidDec == 3962531343) //7th metka, cup 7
  {
    servoHead.write(83);

    delay(3000);

    tone(5, 200, 500); 
    servoBack.write(45); 
    delay(5000); 
    tone(5, 500, 500); 
    servoBack.write(0);  
    delay(1000);   

    servoHead.write(12);

  }
    if (uidDec == 2888789519) //8th metka, cup 8
  {
    servoHead.write(125);

    delay(3000);

    tone(5, 200, 500); 
    servoBack.write(45); 
    delay(5000); 
    tone(5, 500, 500); 
    servoBack.write(0);  
    delay(1000);   

    servoHead.write(12);

  }

}
