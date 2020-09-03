#include <Adafruit_CircuitPlayground.h> // include the adafruit circuit playground library 

int value; // this variable will store our light sensor value allowing us to do THINGS with it!
int THRESHOLD = 100; // at what value or lower do we trigger our interactivity?

void setup() {
  Serial.begin(9600); // initialize serial
  CircuitPlayground.begin(); // initialize Circuit Playground
}

void loop() {
  value = CircuitPlayground.lightSensor(); // update "value" to store the light sensor reading

  Serial.print("Light Sensor: "); // print out "light sensor"
  Serial.println(value); // print the current value for the light sensor

  while (value < THRESHOLD) {
    CircuitPlayground.playTone(500,1000); 
    Serial.println("TRIGGER INTERACTIVITY");
    value = CircuitPlayground.lightSensor(); // update "value" to store the light sensor reading
    delay(100);

  }

  delay(100); // delay of 1 second (1000 milliseconds) between readings
}
