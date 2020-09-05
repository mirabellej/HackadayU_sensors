#include <Adafruit_CircuitPlayground.h> // include the adafruit circuit playground library 

float tempF; // this variable will store our light sensor value allowing us to do THINGS with it!
int THRESHOLD = 82; // at what value or lower do we trigger our interactivity?

void setup() {
  Serial.begin(9600); // initialize serial
  CircuitPlayground.begin(); // initialize Circuit Playground
}

void loop() {
  tempF = CircuitPlayground.temperatureF();

  while (tempF > THRESHOLD) {
    tempF = CircuitPlayground.temperatureF();
    Serial.println("TRIGGER INTERACTIVITY");
    for (int i = 0; i < 10; i++) { // use a for loop to go from one pixel to the next
      CircuitPlayground.setPixelColor(i, 128,   0,   128); // and set the color for the that pixel in RGB
    }
    CircuitPlayground.playTone(500, 2000);
    delay(200);
  }

  delay(100); // delay of 100 milliseconds between readings
}
