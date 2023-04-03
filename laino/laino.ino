#include <Adafruit_NeoPixel.h>
#define LED_STRIP 7
#define NUM_LEDS 49

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_STRIP, NEO_GRB + NEO_KHZ800);

int fixedLED[49];
int fixedLED2[49];
int led_connections[49][4] = {
  {1, 6, 13, 42},  // LED 0
  {0, 2, 12, 43},   // LED 1
  {1, 3, 11, 44},   // LED 2
  {2, 4, 10, 45},  // LED 3
  {3, 5, 9, 46},   // LED 4
  {4, 6, 8, 47},// LED 5
  {5, 0, 7, 48},// LED 6
    
  {13, 8, 20, 6},  // LED 7
  {7, 9, 19, 5},  // LED 8
  {8, 10, 18, 4},// LED 9
  {9, 11, 17, 3},// LED 10
  {10, 12, 16, 2}, // LED 11
  {11, 13, 15, 1}, // LED 12
  {12, 7, 14, 0},// LED 13
  
  {20, 15, 13, 27},// LED 14
  {14, 16, 12, 26}, // LED 15
  {15, 17, 11, 25},// LED 16
  {16, 18, 10, 24}, // LED 17
  {17, 19, 9, 23},// LED 18
  {18, 20, 8, 22}, // LED 19
  {19, 14, 7, 21},// LED 20
  
  {27, 22, 20, 34},// LED 21
  {21, 23, 19, 33}, // LED 22
  {22, 24, 18, 32},// LED 23
  {23, 25, 17, 31}, // LED 24
  {24, 26, 16, 30},// LED 25
  {25, 27, 15, 29}, // LED 26
  {26, 21, 14, 28},// LED 27  
  
  {34, 29, 27, 41},// LED 28
  {28, 30, 26, 40}, // LED 29
  {29, 31, 25, 39},// LED 30
  {30, 32, 24, 38}, // LED 31
  {31, 33, 23, 37},// LED 32
  {32, 34, 22, 36}, // LED 33
  {33, 28, 21, 35},// LED 34
  
  {41, 36, 34, 48},// LED 35
  {35, 37, 33, 47}, // LED 36
  {36, 38, 32, 46},// LED 37
  {37, 39, 31, 45}, // LED 38
  {38, 40, 30, 44},// LED 39
  {39, 41, 29, 43}, // LED 40
  {40, 35, 28, 42},// LED 41
  
  {48, 43, 0, 41},// LED 42
  {42, 44, 40, 1}, // LED 43
  {43, 45, 39, 2},// LED 44
  {44, 46, 38, 3}, // LED 45
  {45, 47, 37, 4},// LED 46
  {46, 48, 36, 5}, // LED 47
  {47, 42, 35, 6},// LED 48   
    
};

int j = 0;
int k = 0;
int xPin = A2;
int yPin = A1;
int sw = 8;
int position = 0;
int button;


//Player 2
int xPin2 = A3;
int yPin2 = A4;
int sw2 = 4;
int position2 = 7;
int button2;


void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to "off"
  strip.setBrightness(25);
  pinMode(sw, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  Serial.begin(9600);
  for (int x = 0; x < NUM_LEDS; x++) {
    fixedLED[x] = 1000;
  }

  for (int x = 0; x < NUM_LEDS; x++) {
    fixedLED2[x] = 1000;
  }

}




int lastPosition = 0;
int currentPosition = 0;
int currentPositionY = 0;
int lastPositionY = 0;


// Player 2
int lastPosition2 = 0;
int currentPosition2 = 0;
int currentPositionY2 = 0;
int lastPositionY2 = 0;

bool found = false;
// Player 2
bool found2 = false;

int numElements;
int randomLED = 0;
int patternLED[7];
int row; 
int last_row_position;
//Player2
int row2; 
int last_row_position2;




void loop() {
  currentPosition = analogRead(xPin);
  currentPositionY = analogRead(yPin);
  currentPosition2 = analogRead(xPin2);
  currentPositionY2 = analogRead(yPin2);
  button = digitalRead(sw);
  button2 = digitalRead(sw2);
  row = position / 7 + 1;
  last_row_position = 7 * row - 1;
  
  row2 = position2 / 7 + 1;
  last_row_position2 = 7 * row2 - 1;

  if (currentPosition != lastPosition) {
    if (row % 2 == 1) {
      if (currentPosition == 1023) {
        if (position == 6) {
          position = 0;
        } else if (position == 13) {
          position = 7;
        } else if (position == 20) {
          position = 14; 
        } else if (position == 27) {
          position = 21; 
        } else if (position == 34) {
          position = 28; 
        } else if (position == 41) {
          position = 35; 
        }else if (position == 48) {
          position = 42; 
        }  else {
          position++;
        }
      } else if (currentPosition == 0) {
          if (position == 0) {
            position = 6;
          } else if (position == 7) {
            position = 13;
          } else if (position == 14) {
            position = 20; 
          } else if (position == 21) {
            position = 27; 
          } else if (position == 28) {
            position = 34; 
          } else if (position == 35) {
            position = 41; 
          } else if (position == 42) {
            position = 48; 
          } else {
            position--;
          }
        }
    } else {
      if (currentPosition == 1023) {
        if (position == 0) {
            position = 6;
          } else if (position == 7) {
            position = 13;
          } else if (position == 14) {
            position = 20; 
          } else if (position == 21) {
            position = 27; 
          } else if (position == 28) {
            position = 34; 
          } else if (position == 35) {
            position = 41; 
          } else if (position == 42) {
            position = 48; 
          } else {
            position--;
          }
      } else if (currentPosition == 0) {
          if (position == 6) {
          position = 0;
        } else if (position == 13) {
          position = 7;
        } else if (position == 20) {
          position = 14; 
        } else if (position == 27) {
          position = 21; 
        } else if (position == 34) {
          position = 28; 
        } else if (position == 41) {
          position = 35; 
        }else if (position == 48) {
          position = 42; 
        }  else {
          position++;
        }
        }
    }
   	// Player 1
    strip.setPixelColor(position, 255, 0, 0);
    strip.show();
    
  }

  //Serial.println(currentPositionY);
  if (currentPositionY != lastPositionY) {
    if (currentPositionY == 1023) {
      // down
      row = position / 7 + 1;
      last_row_position = 7 * row - 1;    

      if (row != 7) {
        position = (last_row_position + 1) + (last_row_position - position); 
      } else {
        position = 6 - (last_row_position - position);        
      }
    }
    else if (currentPositionY == 0) {
      //up
      row = position / 7 + 1;
      last_row_position = 7 * row - 1;
      if (row != 1) {
        position = (last_row_position - 7) - abs((last_row_position - 6) - position);
      } else {
        position = 48 - (last_row_position - position);
      }    
    }
   
    position = position % NUM_LEDS;
    if (position < 0) {
     position = NUM_LEDS + position; 
    }
    strip.setPixelColor(position, 255, 0, 0);
    strip.show();
    
  }


  //Player2

  if (currentPosition2 != lastPosition2) {
    if (row2 % 2 == 1) {
      if (currentPosition2 == 1023) {
        if (position2 == 6) {
          position2 = 0;
        } else if (position2 == 13) {
          position2 = 7;
        } else if (position2 == 20) {
          position2 = 14; 
        } else if (position2 == 27) {
          position2 = 21; 
        } else if (position2 == 34) {
          position2 = 28; 
        } else if (position2 == 41) {
          position2 = 35; 
        }else if (position2 == 48) {
          position2 = 42; 
        }  else {
          position2++;
        }
      } else if (currentPosition2 == 0) {
          if (position2 == 0) {
            position2 = 6;
          } else if (position2 == 7) {
            position2 = 13;
          } else if (position2 == 14) {
            position2 = 20; 
          } else if (position2 == 21) {
            position2 = 27; 
          } else if (position2 == 28) {
            position2 = 34; 
          } else if (position2 == 35) {
            position2 = 41; 
          } else if (position2 == 42) {
            position2 = 48; 
          } else {
            position2--;
          }
        }
    } else {
      if (currentPosition2 == 1023) {
        if (position2 == 0) {
            position2 = 6;
          } else if (position2 == 7) {
            position2 = 13;
          } else if (position2 == 14) {
            position2 = 20; 
          } else if (position2 == 21) {
            position2 = 27; 
          } else if (position2 == 28) {
            position2 = 34; 
          } else if (position2 == 35) {
            position2 = 41; 
          } else if (position2 == 42) {
            position2 = 48; 
          } else {
            position2--;
          }
      } else if (currentPosition2 == 0) {
          if (position2 == 6) {
          position2 = 0;
        } else if (position2 == 13) {
          position2 = 7;
        } else if (position2 == 20) {
          position2 = 14; 
        } else if (position2 == 27) {
          position2 = 21; 
        } else if (position2 == 34) {
          position2 = 28; 
        } else if (position2 == 41) {
          position2 = 35; 
        }else if (position2 == 48) {
          position2 = 42; 
        }  else {
          position2++;
        }
        }
    }
   	
    //Player 2
    strip.setPixelColor(position2, 0, 255, 0);
    strip.show();
  }

  if (currentPositionY2 != lastPositionY2) {
    if (currentPositionY2 == 1023) {
      // down
      row2 = position2 / 7 + 1;
      last_row_position2 = 7 * row2 - 1;    

      if (row2 != 7) {
        position2 = (last_row_position2 + 1) + (last_row_position2 - position2); 
      } else {
        position2 = 6 - (last_row_position2 - position2);        
      }
    }
    else if (currentPositionY2 == 0) {
      //up
      row2 = position2 / 7 + 1;
      last_row_position2 = 7 * row2 - 1;
      if (row2 != 1) {
        position2 = (last_row_position2 - 7) - abs((last_row_position2 - 6) - position2);
      } else {
        position2 = 48 - (last_row_position2 - position2);
      }    
    }
   
    position2 = position2 % NUM_LEDS;
    if (position2 < 0) {
     position2 = NUM_LEDS + position2; 
    }
    //Player 2
    strip.setPixelColor(position2, 0, 255, 0);
    strip.show();
  }

  if (button == LOW) {
    fixedLED[position] = position;
    if (fixedLED2[position] != 1000) {
      fixedLED2[position] = 1000;
    }
    if (position == position2) {
      pattern(position);
      for (int i = 0; i < 7; i++) {
        if (patternLED[i] == position) {
          strip.setPixelColor(patternLED[i], 128, 128, 0);
          strip.show();
        } else {
          strip.setPixelColor(patternLED[i], 0, 0, 255);
          strip.show();
        }
      }
      delay(1000);
      for (int i = 0; i < 7; i++) {
        if (patternLED[i] != position) {
          strip.setPixelColor(patternLED[i], 0, 0, 0);
          strip.show();
        }
      }   
    }  
  }

  if (button2 == LOW) {
    // change to second position -player 2
    fixedLED2[position2] = position2;
    if (fixedLED[position2] != 1000) {
      fixedLED[position2] = 1000;
    }
    if (position2 == position) {
      pattern(position2);
      for (int i = 0; i < 7; i++) {
        if (patternLED[i] == position2) {
        // combine colors here
          strip.setPixelColor(patternLED[i], 0, 255, 0);
          strip.show();
        } else {
          strip.setPixelColor(patternLED[i], 255, 255, 0);
          strip.show();
        }
      }
      delay(1000);
      for (int i = 0; i < 7; i++) {
        if (patternLED[i] != position) {
          strip.setPixelColor(patternLED[i], 0, 0, 0);
          strip.show();
        }
      }
    }    
  }
  setColor(255, 0, 0, 0, 255, 0);
  setColor(255, 0, 0, 0, 255, 0);
  delay(50);
  
  lastPosition = currentPosition;
  lastPositionY = currentPositionY;

  lastPosition2 = currentPosition2;
  lastPositionY2 = currentPositionY2;
}




void pattern(int position) {
  numElements = 4;
  
  randomLED = led_connections[position][random(numElements)];
  patternLED[0] = randomLED;
  
  for (int i = 1; i < 7; i++) {
   randomLED = led_connections[randomLED][random(numElements)];
   patternLED[i] = randomLED; 
  }
}

void setColor(int R, int G, int B, int R2, int G2, int B2) {
  for (int i = 0; i < NUM_LEDS; i++) {
      for (int j = 0; j < NUM_LEDS; j++) {
        if (i == fixedLED[j]) {
          found = true;
          break;
        } else if (i == fixedLED2[j]){
          found2 = true;
          break;
        } else {
          found = false;
          found2 = false;
        }
      }
      if (!found && !found2) {
        strip.setPixelColor(i, 0, 0, 0);
      } else if (found){
        strip.setPixelColor(i, R, G, B); // color of first player
    	  strip.show();
      } else if (found2) {
        strip.setPixelColor(i, R2, G2, B2); // color of second player
    	  strip.show();
      }
    }
    strip.show();
}
