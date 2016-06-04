#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f);  // Set the LCD I2C address

#define BACKLIGHT_PIN     7 

void setup()
{
 lcd.begin(20,4)
}

void loop()
{

}
