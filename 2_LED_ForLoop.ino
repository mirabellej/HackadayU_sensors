/*
 * How to Use a For Loop to Set All the Pixels to a Color at Once! 
 * by Mirabelle Jones
 * Github.com/mirabellej
 */

#include <Adafruit_CircuitPlayground.h> // include the adafruit library so we can use its functions

void setup() {
  CircuitPlayground.begin(); // initialize / wake up our Circuit Playground
}

void loop() {
  CircuitPlayground.clearPixels(); // turns all the LEDs OFF 

  delay(500); // small delay

  for (int i = 0; i < 10; i++){ // use a for loop to go from one pixel to the next
    CircuitPlayground.setPixelColor(i, 128,   0,   128); // and set the color for the that pixel in RGB
  }
 
  delay(5000); // how long do we want the pixels to be on for? 
}
