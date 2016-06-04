#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define BACKLIGHT 8

LiquidCrystal_I2C iLCD(0x3f,2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup ( )
{
  Serial.begin(9600);
   iLCD.backlight();
   iLCD.begin ( 20, 4 );
   iLCD.home();
   iLCD.print("test");
   iLCD.setCursor(0,1);
   iLCD.print("AM I better?");
   iLCD.setCursor(0,2);
   
}

void loop ()
{
    {
    // when characters arrive over the serial port...
    if (Serial.available()) {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      iLCD.clear();
      // read all the available characters
      while (Serial.available() > 0) {
        // display each character to the LCD
        iLCD.write(Serial.read());
      }
    }
  }

}
