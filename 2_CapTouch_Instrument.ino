#include <Adafruit_CircuitPlayground.h>

#define CAP_THRESHOLD   1016
#define DEBOUNCE        100


uint8_t pads[] = {3, 2, 0, 1, 6, 9, 10}; // this lists all of the touch pads 
uint8_t numberOfPads = sizeof(pads)/sizeof(uint8_t);

void takeAction(uint8_t pad) {
  
  // this is a switch case statement that will do something different for each pad!
  // it's like an IF statement but better for when you have lots of inputs or want to do different things!
  switch (pad) {
    
    //  Labeled Pin A4
    case 3:
      Serial.println("Touched D3 / A4!"); 
      CircuitPlayground.playTone(5000, 500);
      break;
      
    //  Labeled Pin A5
    case 2:
      Serial.println("Touched D2 / A5!"); 
      CircuitPlayground.playTone(4000, 500);
      break;
      
    //  Labeled Pin A6
    case 0:
      Serial.println("Touched D0 / A6!"); 
      CircuitPlayground.playTone(1000, 500);
      break;
      
    //  Labeled Pin A7
    case 1:
      Serial.println("Touched D1 / A7!"); 
      CircuitPlayground.playTone(800, 500);
      break;
      
    // Labeled Pin A1
    case 6:
      Serial.println("Touched D6 / A1!"); 
      CircuitPlayground.playTone(300, 500);
      break;
      
    // Labeled Pin A2 
    case 9:
      Serial.println("Touched D9 / A2!"); 
      CircuitPlayground.playTone(200, 500);
      break;
      
    // Labeled Pin A3 
    case 10:
      Serial.println("Touched D10 / A3!"); 
      CircuitPlayground.playTone(100, 500);
      break;
      
    // It's nice to include a default case... just in case! 
    default:
      Serial.println("THIS SHOULD NEVER HAPPEN.");
  }
}

boolean capButton(uint8_t pad) {
  // Check if capacitive touch exceeds threshold.
  if (CircuitPlayground.readCap(pad) >= CAP_THRESHOLD) {
    return true;  
  } else {
    return false;
  }
}

void setup() {
  // Initialize serial.
  Serial.begin(9600); 
  
  // Initialize Circuit Playground library.
  CircuitPlayground.begin();
}

void loop() {
  // Loop over every pad.
  for (int i=0; i<numberOfPads; i++) {
    
    // Check if pad is touched.
    if (capButton(pads[i])) {
      
      // Do something.
      takeAction(pads[i]);
      
      // But not too often.
      delay(DEBOUNCE);
    }
  }
}
