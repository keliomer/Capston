#include <Wire.h>
#include <L3G4200D.h> //Gyroscope Library
#include <LCD.h> //Overridden LCD Library 
#include <LiquidCrystal_I2C.h>

//
LiquidCrystal_I2C iLCD(0x3f,2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
L3G4200D gyro;

//Initialize PWM pins controlled from input (pots/gyro)
const int inGreenPin = 3;
const int inRedPin = 6;
const int inBluePin = 5;


//Initialize PWM pins controlled from Arduino
const int ardBlue = 11;
const int ardRed = 10;
const int ardGreen = 9;
//const int test = 13;

//connections to button to use as a momentary switch to generate new colors
const int momentary = 12;
int mState = 0;

//color for input LED (0-255) (from input)
int redIn = 1;
int greenIn= 1;
int blueIn= 1;

//set random values for PWM so the chance of  both LEDS matching immefiately is very small
int randRedArd = random(256);
int randGreenArd = random(256);
int randBlueArd = random(256);

//Initialize gyro axes
int x,y,z;

// Initialize Output value Strings
char ardStg[20];
char inStg[20];

void setup() {
  //Set up for LCD
  Serial.begin(9600);
  //Turn on backlight
  iLCD.backlight();
  
  //set first cursor
  iLCD.begin ( 20, 4 );
  iLCD.home();
  iLCD.print("Lock:");
  iLCD.setCursor(0,2);
  iLCD.print("Key:");
  

  Wire.begin();
  gyro.initialize(500);
  pinMode(inBluePin, OUTPUT);
  pinMode(inRedPin, OUTPUT);
  pinMode(inGreenPin,OUTPUT);
  //pinMode(test,OUTPUT);
  pinMode(momentary,INPUT);
//  digitalWrite(test,0);
  randomSeed(analogRead(0)); //makes sure colors are well randomized

}

void loop() {

  mState = digitalRead(momentary);
  //This is to generate a random color
  if (mState == HIGH){
    randGreenArd = random(256);
    randRedArd = random(256);
    randBlueArd = random(256);
      }
    analogWrite(ardRed,255 - randRedArd);
    analogWrite(ardGreen,255 - randGreenArd);
    analogWrite(ardBlue,255 - randBlueArd);
  
    //digitalWrite(test, HIGH);
    
    sprintf(ardStg, "R:%03d G:%03d B:%03d", randRedArd, randGreenArd, randBlueArd);
    // Comment out below to use only 
    

    //Sets up axis values
    x = gyro.getX();
    y = gyro.getY();
    z = gyro.getZ();
//    if (randGreen == 0 || randGreen == 255):
// The gyro measures degrees/second so we need to figure out how much of a turn we want to be fromm 0-255

   

    int g = int(x/1000);
    int b = int(y/1000);
    int r = int(z/1000);
    
  greenIn += g;
  blueIn += b;
  redIn += r;

if (greenIn <0 || greenIn > 255){
      greenIn = 255 - greenIn;
    }
    if (blueIn < 0 || blueIn > 255){
      blueIn = 255 - blueIn;
    }

    if (redIn < 0 || redIn > 255){
      redIn = 255 - redIn;
    } 
  
  sprintf(inStg, "R:%03d G:%03d B:%03d", redIn, greenIn, blueIn);
  
  //Comment out below to use only LEDs (no text)
  iLCD.setCursor(0,1);
  iLCD.print(ardStg);
  iLCD.setCursor(0,3);
  iLCD.print(inStg);

  analogWrite(inRedPin,255 - redIn);
  analogWrite(inGreenPin,255 - greenIn);
  analogWrite(inBluePin,255 - blueIn);

  if (greenIn == randGreenArd && redIn == randRedArd && blueIn == randBlueArd){
    x = 0;
    y = 0;
    z = 0;
    iLCD.clear();
    iLCD.home();
    iLCD.print("Unlocked!");
    delay(10000);
    exit(0);
  }
  
    }
