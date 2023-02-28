# KeyProteck Pin Door Lock Control Application

This is a Hardware Hackathon Project made in E2C2 a Electrical Engineering Competion at the University of Alberta, its an Arduino application that controls a pin door lock called KeyProteck. The application uses a keypad to enter a four-digit code to unlock the door.

## Requirements

- Arduino board
- Servo motor
- Keypad
- Green LED
- Red LED
- Buzzer

## Installation

1. Install the Arduino IDE on your computer
2. Clone or download this repository to your computer
3. Open the application code in the Arduino IDE
4. Connect the Arduino board to your computer using a USB cable
5. Select the board and port in the Arduino IDE
6. Upload the code to the Arduino board

## Usage

1. Connect the servo motor to pin 12 of the Arduino board
2. Connect the keypad to the defined pins in the code
3. Connect the blue LED to pin 10 of the Arduino board
4. Connect the red LED to pin 11 of the Arduino board
5. Connect the buzzer to pin 13 of the Arduino board
6. Enter the four-digit code on the keypad and press the pound key
7. If the code is correct, the Green LED will turn on, the servo motor will spin 90 degrees clockwise to unlock the door, and the Red LED will turn on after 20 seconds. If the code is incorrect, the red LED will turn on, and the buzzer will beep for a short period.

## Authors

This application was created by Yahya Mula-Hussain, Abdul Wasay Syed and Omar Abdelghany.

## Acknowledgments

This application was created with the help of the [Adafruit Keypad library](https://github.com/adafruit/Adafruit_Keypad) and the [Servo library](https://www.arduino.cc/en/Reference/Servo).
