const int buttonPin = 7;               // Button on digital pin 7
const int ledPins[4] = {1, 2, 3, 4};   // LED pins
int counter = 0;                        // Number to display (0-15)
       // Debounce timer

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);    // Set LED pins as output
    }
    
    pinMode(buttonPin, INPUT_PULLUP);   // Enable internal pull-up resistor
}

void loop() {
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
        digitalWrite(ledPins[i], (n >> i) & 1);  // Display the binary value on LEDs
    }
}
