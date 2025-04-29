const int ledPins[4] = {1, 2, 3, 4};  // LED pins
int counter = 0;                      // Number to display (0-15)

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
    }


void loop() {
    displayBinary(counter);  // Show counter in binary
    delay(1000);             // Wait 1 second

    counter = (counter + 1) % 16;  // Increment and wrap at 15
}

void displayBinary(int n) {
    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], (n >> i) & 1);
    }
}
