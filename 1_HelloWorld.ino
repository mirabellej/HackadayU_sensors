#include <Adafruit_CircuitPlayground.h>

void setup() {
  // Initialize serial.
  Serial.begin(9600); 
  
  // Initialize Circuit Playground library.
  CircuitPlayground.begin();

  Serial.println("Started up!"); // This will only print once!

  delay(3000); 
}


void loop() {

      Serial.println("Hello World"); // This prints a message once per loop!

      // Challenge: Change the above to include your name instead of "world"

      // Challenge: Add a second message below:

      // Challenge: Add pseudocode for a program that blinks an LED on and off
      
    
      delay(250); // Delay between readings and print statements - challenge: change 250 to another number 
}
