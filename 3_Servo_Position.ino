// Using this sketch we can tell the servo to go to a specific position in degrees!
#include <Servo.h> // This is a servo library

#define SERVO_PIN 10 // labeled A3 on Circuit Playground 
#define DELAY 1000 // how long do we want to wait between movements? 

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(10);  // attaches the servo on pin 10 to the object 
}

void loop() {
    myservo.write(90);              // tell servo to go to position in () - 90 is 90 degrees!
    delay(DELAY);                       // waits for the value of DELAY (see top of sketch!)
  
    myservo.write(0);              // tell servo to go to position in () - 0 is back to start!
    delay(DELAY);                       // waits for the value of DELAY (see top of sketch!)

}
