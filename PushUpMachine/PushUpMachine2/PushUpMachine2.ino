#include <Servo.h> 
int buttonPin = 12; // the number of the push button pin 
int ledPin = 9;  

int binaryInputPin = 7;

int servoPin = 13;
Servo jackedArm;
int currentPos = 155;
int progress = 0;

bool working = true;
// the number of the LED pin 

int counter = 0;          // Counter variable
bool lastButtonState = HIGH;  // Track last button state

const int ledPins[4] = {1, 2, 3, 4};  // LED pins  
unsigned long lastPressTime = 0; 
void setup() { 
pinMode(buttonPin, INPUT);  // set push button pin into input mode  
pinMode(ledPin, OUTPUT);
jackedArm.attach(servoPin);
// set LED pin into output mode
for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
}
pinMode(binaryInputPin, INPUT_PULLUP);   // Enable internal pull-up resistor
} 
void loop() { 
  displayBinary(counter);
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
  displayBinary(0);  
// switch off LED 
// if the button is pressed 
// switch on LED 
}
    int buttonState = digitalRead(buttonPin);  // Read the button state
    unsigned long currentTime = millis();

    // Simple debounce: Ignore presses within 200ms
    if (buttonState == LOW && currentTime - lastPressTime > 200) {
        counter = (counter + 1) % 16;  // Increment & wrap at 15
        displayBinary(counter);        // Update LEDs to display binary
        lastPressTime = currentTime;   // Update debounce timer
    }
}
void displayBinary(int n) {
    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], (n >> i) & 1);
    }
}