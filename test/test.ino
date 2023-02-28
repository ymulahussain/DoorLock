#include "Adafruit_Keypad.h"

// define your specific keypad here via PID
#define KEYPAD_PID3844
// define your pins here
// can ignore ones that don't apply
#define R1    2
#define R2    3
#define R3    4
#define R4    5
#define C1    8
#define C2    9
#define C3    10
#define C4    11
// leave this import after the above configuration
#include "keypad_config.h"

//initialize an instance of class Adafruit_Keypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// define the pin for the LED
#define LED_PIN 12

void setup() {
  Serial.begin(9600);
  customKeypad.begin();
  
  // initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  customKeypad.tick();

  String input = "";

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();

    // Add the pressed key to the input string
    input += e.bit.KEY;

    // Check for a specific input sequence
    if (input == "2586") {
      // Turn on the LED
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED on");
      Serial.println("Blue LED is on");  // Print the additional message
      delay(1000);
      
      // Clear the input string
      input = "";
    }
    
    // Print the key and event type
    Serial.print((char)e.bit.KEY);
    if(e.bit.EVENT == KEY_JUST_PRESSED) {
      Serial.println(" pressed");
    } else if(e.bit.EVENT == KEY_JUST_RELEASED) {
      Serial.println(" released");
    }
  }

  // Turn off the LED if the input sequence is no longer being entered
  digitalWrite(LED_PIN, LOW);
}
