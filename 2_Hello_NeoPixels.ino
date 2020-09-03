#include <Adafruit_CircuitPlayground.h> // include the adafruit library so we can use its functions

void setup() {
  CircuitPlayground.begin(); // initialize / wake up our Circuit Playground
}

void loop() {
  CircuitPlayground.clearPixels(); // turns all the LEDs OFF / clear color data

  delay(500); // how long do we want our LED to be off for?

// CircuitPlayground.setPixelColor(pixel number, Red, Green, Blue)
// RGB is on a scale of 0 to 255 
// 255 means 100% that color
// To turn an LED to red we set red to 100% by typing 255 and the other values for Green and Blue to 0 

  CircuitPlayground.setPixelColor(0, 255,   0,   0);
  CircuitPlayground.setPixelColor(1, 128, 128,   0);
  CircuitPlayground.setPixelColor(2,   0, 255,   0);
  CircuitPlayground.setPixelColor(3,   0, 128, 128);
  CircuitPlayground.setPixelColor(4,   0,   0, 255);
  
  CircuitPlayground.setPixelColor(5, 0xFF0000);
  CircuitPlayground.setPixelColor(6, 0x808000);
  CircuitPlayground.setPixelColor(7, 0x00FF00);
  CircuitPlayground.setPixelColor(8, 0x008080);
  CircuitPlayground.setPixelColor(9, 0x0000FF);
 
  delay(5000); // how long do we want the LED to be on for in milliseconds?
}
