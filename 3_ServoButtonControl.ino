#include <Adafruit_CircuitPlayground.h>

// Using this sketch we can sweep the servo back and forth!
#include <Servo.h> // This is a servo library

#define SERVO_PIN 10; // this is labeled A3 on Circuit Playground 

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

bool leftButtonPressed;
bool rightButtonPressed;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  CircuitPlayground.begin();
  myservo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  leftButtonPressed = CircuitPlayground.leftButton();
  rightButtonPressed = CircuitPlayground.rightButton();


  Serial.print("Left Button: ");
  if (leftButtonPressed) {
    // rotate servo from right to left
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else {
    //
  }
  Serial.print("   Right Button: ");
  if (rightButtonPressed) {
    // rotate servo from left to right
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else {
    //
  }
  Serial.println();

  delay(1000);
}
