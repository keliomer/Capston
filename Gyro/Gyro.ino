#include <Wire.h>
#include <Gyro.h>


const int sensorRotationScaleDPS = 250; //(can be 250, 500, or 2000) 
Gyro Gx; 
float angleX;
float angleY; 
float angleZ; 
 
unsigned long SpamTimer; // for Serial output not required for gyro 
void setup()  
{  
Wire.begin(); 
Gx.init(); 
Gx.setupL3G4200D(sensorRotationScaleDPS); 
 
Serial.begin(9600); // for the serial port communications not required for the gyro 
} 
void loop()  
{ 
  Gx.getGyroValues(); 
  angleX = Gx.g.angleX; // Get the X angle  
  angleY = Gx.g.angleY; // Get the Y angle  
  angleZ = Gx.g.angleZ; // get the Z angle 
 
 
// Your code Here!!! 
 
 
// Lets see what we've got! 
  if(millis() >= SpamTimer ) 
  { 
    SpamTimer += 50; 
    Serial.print("X:"); 
    Serial.print(angleX); 
    Serial.print(", "); 
 
    Serial.print("Y:"); 
    Serial.print(angleY); 
    Serial.print(", "); 
 
    Serial.print("Z:"); 
    Serial.print(angleZ); 
    Serial.print(", ");  
  } 
} 
