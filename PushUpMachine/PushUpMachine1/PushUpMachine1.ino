#include <Servo.h> 
int buttonPin = 12; // the number of the push button pin 
int ledPin = 9;  

int servoPin = 13;
Servo jackedArm;
int currentPos = 155;
int progress = 0;

bool working = true;
// the number of the LED pin 
void setup() { 
pinMode(buttonPin, INPUT);  // set push button pin into input mode  
pinMode(ledPin, OUTPUT);
jackedArm.attach(servoPin);
// set LED pin into output mode  
} 
void loop() { 
  if (digitalRead(buttonPin) == HIGH) { // if the button is not pressed 
    working = false;
  }
  else {
    working = true;
  }
if (working) {
  digitalWrite(ledPin, HIGH);
   for (progress = 0; progress <= 65; progress += 1) { // goes from 0 degrees to 180 degrees 
      jackedArm.write(currentPos - progress);
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  currentPos = 155;
  jackedArm.write(currentPos);
  progress = 0;
} else {                               
  digitalWrite(ledPin, LOW);       
// switch off LED 
// if the button is pressed 
// switch on LED 
} 
}