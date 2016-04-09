/*
 Random RGB Color Generator
 */
  
int blue = 11;// the pin that the LED is attached to
int red = 10;
int green = 9;
int pot = A0;
int buttonin = 8;
int buttonout = 2;
int brightness = 0;    // how bright the LED is
int randRed;
int randGreen;
int randBlue;
// the setup routine runs once when you press reset:
void setup() {

  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buttonin,OUTPUT);
  digitalWrite(buttonin, HIGH);
  pinMode(buttonout,INPUT);
  Serial.begin(9600);
 
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(buttonout) == HIGH){
    randGreen = random(256);
    randRed = random(256);
    randBlue = random(256);
    Serial.println("Green:");
    Serial.println(255 -randGreen);
    Serial.println("Red:");
    Serial.println(255 - randRed);
    Serial.println("Blue:");
    Serial.println(255 - randBlue);
    Serial.println("-------------");
  }
  int val = analogRead(pot);
//  analogWrite(blue, val/4); //Shows control with a external source
  analogWrite(blue, randBlue);
  analogWrite(red, randRed);
  analogWrite(green, randGreen);
  delay(10);
}

