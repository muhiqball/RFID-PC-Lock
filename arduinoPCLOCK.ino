#include <SPI.h>
#include <RFID.h>
#include <Keyboard.h>

#define SS_PIN 7
#define RST_PIN 5

RFID rfid(SS_PIN, RST_PIN);
char Enter = KEY_RETURN;
int serNum[5];
int kartu[5] = {75, 185, 161, 13, 94};
int card[5] = {193, 165, 118, 137, 155};//write your RFID card number here 

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.init();

}

void loop()
{
  if (rfid.isCard())
  {
    Serial.println("card available");
    if (rfid.readCardSerial())
    {

      for (int x = 0; x < 10; x++)
      {
        for (int i = 0; i < sizeof(rfid.serNum); i++ )
        {
         // Serial.println(rfid.serNum[i]); //to serial print the scanned RFID card number, note it down and change it on line 10
          if (rfid.serNum[i] == kartu[i])
          {
         Keyboard.press(KEY_LEFT_GUI); //Press the left windows key.
           Keyboard.press('l');              
  Keyboard.releaseAll(); //Release all keys. 
  Keyboard.press(Enter);
   Keyboard.release(Enter); //Press the Enter key.
   Keyboard.releaseAll();
  Keyboard.print("pass");                    // Change this value to your Windows PIN/Password.
  Keyboard.releaseAll();
  delay(100);
  Keyboard.press(Enter);
  Keyboard.releaseAll();
  }
else if (rfid.serNum[i] == card[i])
          { 
  Keyboard.print("pass");                    // Change this value to your Windows PIN/Password.
  Keyboard.releaseAll();
  delay(100);
  Keyboard.press(Enter);
  Keyboard.releaseAll();
  }else
 {
  return;
 } 
        }
      }
    }
  }

}
