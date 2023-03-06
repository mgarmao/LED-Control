#include <Arduino.h>
void purple();
void yellow();
void white();
void off();
void turnRed();
void turnBlue();
void orange();

int green = 10;
int blue = 7;
int red = 11;

void setup() {
  Serial.begin(9600);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  delay(100);
}

void loop() {
  if (Serial.available() > 0) { // If there's data available on the serial port
    int data = Serial.read(); // Read the incoming data
    Serial.println(data);
    if(data==1){
      yellow();
    }
    else if(data==2){
      purple();
    }
    else{
      turnRed();
    }
    unsigned long startTimer = millis();
    while(millis()-startTimer<=5000&&!(Serial.available() > 0)){
      
    }
  }
  else{
    off();
  }
  delay(100);
}

void purple(){
  analogWrite(red,50);
  analogWrite(green,237);
  analogWrite(blue,0);
}

void yellow(){
  analogWrite(red,0);
  analogWrite(green,75);
  analogWrite(blue,255);
}

void turnRed(){
  analogWrite(red,0);
  analogWrite(green,255);
  analogWrite(blue,255);
}

void turnBlue(){
  analogWrite(red,255);
  analogWrite(green,255);
  analogWrite(blue,0);
}

void white(){
  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,0);
}

void orange(){
  analogWrite(red,0);
  analogWrite(green,230);
  analogWrite(blue,255);
}

void off(){
  analogWrite(red,255);
  analogWrite(green,255);
  analogWrite(blue,255);
}