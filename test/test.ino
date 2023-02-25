#include <Keypad.h>
#include <Servo.h>

// Define the pins for the servo motor and the keypad
#define SERVO_PIN 12
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 10};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Define the variables for the servo motor and the keypad input
Servo myservo;
int angle = 0;
String input = "";

void setup() {
  // Initialize the servo motor and set it to 0 degrees
  myservo.attach(SERVO_PIN);
  myservo.write(angle);
  // Initialize the serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Get the key input from the keypad
  char key = keypad.getKey();
  if (key != NO_KEY) {
    // Add the key to the input string
    input += key;
    // Check if the input string is "1089"
    if (input == "1089") {
      // Turn the servo motor to 90 degrees
      angle = 90;
      myservo.write(angle);
      // Print a message to the serial monitor for debugging
      Serial.println("Servo motor turned");
      // Reset the input string
      input = "";
    }
  }
}
