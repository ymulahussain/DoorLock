#include <Servo.h>
#include "Adafruit_Keypad.h"

// define your specific keypad here via PID
#define KEYPAD_PID3844
// define your pins here
// can ignore ones that don't apply
#define R4    2
#define R3    3
#define R2    4
#define R1    5
#define C4    6
#define C3    7
#define C2    8
#define C1    9

// define LED pins
#define BLUE_LED_PIN 10
#define RED_LED_PIN 11

// define servo pin
#define SERVO_PIN 12
#define Blink 200
#define Buzzer_PIN 13

// leave this import after the above configuration
#include "keypad_config.h"


//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Array to store the last 4 keys pressed
char lastKeys[4] = {' ', ' ', ' ', ' '};

// Create a Servo object
Servo myServo;

void setup() {
  Serial.begin(9600);
  customKeypad.begin();
  
  // Set LED pins as output
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(Buzzer_PIN,OUTPUT);
  
  // Attach servo to pin 12
  myServo.attach(SERVO_PIN);
  
  // Initialize servo at 0 degrees
  myServo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    char key = (char)e.bit.KEY;
    if(e.bit.EVENT == KEY_JUST_PRESSED) {
      Serial.print(key);
      if (key != '#') {
        // shift the previous keys in the array and add the new key
        for (int i = 0; i < 3; i++) {
          lastKeys[i] = lastKeys[i+1];
        }
        lastKeys[3] = key;
      } else {
        // check if the code is correct
        if (lastKeys[0] == '1' && lastKeys[1] == '9' && lastKeys[2] == '3' && lastKeys[3] == '9') {
          Serial.println(" Code is Correct");
          digitalWrite(BLUE_LED_PIN, HIGH);  // turn on blue LED
          digitalWrite(RED_LED_PIN, LOW);   // turn off red LED
          
          // spin servo 90 degrees clockwise
          myServo.write(90);
          delay(5000); // wait 20 seconds
          myServo.write(0);  // spin servo 90 degrees counterclockwise to 0 degrees
          digitalWrite(BLUE_LED_PIN, LOW);   // turn off blue LED
          digitalWrite(RED_LED_PIN, HIGH);  // turn on red LED
        } else {
          Serial.println(" Code is Incorrect");
          digitalWrite(BLUE_LED_PIN, LOW);   // turn off blue LED
          digitalWrite(RED_LED_PIN, HIGH);  // turn on red LED 
          digitalWrite(Buzzer_PIN, HIGH);
          delay(Blink);
          digitalWrite(RED_LED_PIN, LOW);
          delay(Blink);
          digitalWrite(RED_LED_PIN, HIGH);
          delay(Blink);
          digitalWrite(RED_LED_PIN, LOW);
          digitalWrite(Buzzer_PIN, LOW);
          delay(Blink);
          digitalWrite(RED_LED_PIN, HIGH);
          delay(Blink);
          digitalWrite(RED_LED_PIN, LOW);
          delay(Blink);
          digitalWrite(RED_LED_PIN, HIGH);
          
        }
      }
    }
  }

  delay(10);
}

void lock()
{
  // Do nothing for now
}
