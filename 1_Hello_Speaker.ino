#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  delay(1000);
}

void loop() {
  // (tone in hz, duration) - recommend 60 Hz to 9000 Hz
  CircuitPlayground.playTone(5000, 2000);
  delay(1000);
  
  // copy and past code to make your song here: 
}
