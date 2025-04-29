int buttonPin = 9;  // Pin where button is connected
//int ledPin = 9;    // Pin where LED is connected
int buttonState = 0; // Variable to store button state

void setup() {
  pinMode(buttonPin, INPUT);   // Set button pin as input
  //pinMode(ledPin, OUTPUT);     // Set LED pin as output
  Serial.begin(9600); 

}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the button state

  if (buttonState == LOW) { // If button is pressed
    // digitalWrite(ledPin, HIGH); // Turn LED on
    Serial.println("button off");

  } else {
    // digitalWrite(ledPin, LOW);  // Turn LED off
    Serial.println("button on");
  }
  delay(500);
}
