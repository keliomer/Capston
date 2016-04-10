#include <Wire.h>
#include <L3G4200D.h>

/*
 Random RGB Color Generator
 */

L3G4200D gyro;

int blue = 11;// the pin that the Blue is attached to
int red = 10;
int green = 9;
//int pot = A0;
int buttonin = 8;
int buttonout = 2;
int brightness = 0;    // how bright the LED is
byte randRed = 0;
byte randGreen;
byte randBlue;
int x,y,z;
// the setup routine runs once when you press reset:
void setup() {
  Wire.begin();
  gyro.initialize(500);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buttonin,OUTPUT);
  digitalWrite(buttonin, HIGH);
  pinMode(buttonout,INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
 
}

// the loop routine runs over and over again forever:
void loop() {
  
/*
Change this to a function that will create a random color on a separate LED
*/
//  if (digitalRead(buttonout) == HIGH){
//    randGreen = random(256);
//    randRed = random(256);
//    randBlue = random(256);
    x = gyro.getX();
    y = gyro.getY();
    z = gyro.getZ();
//    if (randGreen == 0 || randGreen == 255):
    randGreen += byte(x/180);
    randBlue += byte(y/180);
    randRed += byte(z/180);
    
    
    
    Serial.println("Green:");
    Serial.println(randGreen);
    Serial.println("Red:");
    Serial.println(randRed);
    Serial.println("Blue:");
    Serial.println(randBlue);
    Serial.println("-------------");
//  analogWrite(blue, val/4); //Shows control with a external source
  analogWrite(blue, 255 - randBlue);
  analogWrite(red, 255 - randRed);
  analogWrite(green, 255- randGreen);
 
}

