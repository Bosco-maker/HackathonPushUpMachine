#include <Servo.h> 
 
Servo myservo;              // create servo object to control a servo 
 
int pos = 0;                // variable to store the servo position 
int servoPin = 3;           // define the pin of servo signal line 
 
void setup() { 
  myservo.attach(servoPin); // attaches the servo on servoPin to the servo object 
} 
 
void loop() {
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);        // tell servo to go to position in variable "pos"                        // waits 15ms for the servo to reach the position 
} 
