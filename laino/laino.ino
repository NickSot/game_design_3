#include <Adafruit_NeoPixel.h>
#define LED_STRIP 7
#define NUM_LEDS 49

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_STRIP, NEO_GRB + NEO_KHZ800);

int fixedLED[49];
int led_connections[49][4] = {
  {1, 6, 7, 42},  // LED 0
  {0, 2, 8, 43},   // LED 1
  {1, 3, 9, 44},   // LED 2
  {2, 4, 10, 45},  // LED 3
  {3, 5, 11, 46},   // LED 4
  {4, 6, 12, 47},// LED 5
  {5, 0, 13, 48},// LED 6
    
  {13, 8, 14, 0},  // LED 7
  {7, 9, 15, 1},  // LED 8
  {8, 10, 16, 2},// LED 9
  {9, 11, 17, 3},// LED 10
  {10, 12, 18, 4}, // LED 11
  {11, 13, 19, 5}, // LED 12
  {12, 7, 20, 6},// LED 13
  
  {20, 15, 7, 21},// LED 14
  {14, 16, 8, 22}, // LED 15
  {15, 17, 9, 23},// LED 16
  {16, 18, 10, 24}, // LED 17
  {17, 19, 11, 25},// LED 18
  {18, 20, 12, 26}, // LED 19
  {19, 14, 13, 27},// LED 20
  
  {27, 22, 14, 28},// LED 21
  {21, 23, 15, 29}, // LED 22
  {22, 24, 16, 30},// LED 23
  {23, 25, 17, 31}, // LED 24
  {24, 26, 18, 32},// LED 25
  {25, 27, 19, 33}, // LED 26
  {26, 21, 20, 34},// LED 27  
  
  {34, 29, 21, 35},// LED 28
  {28, 30, 22, 36}, // LED 29
  {29, 31, 23, 37},// LED 30
  {30, 32, 24, 38}, // LED 31
  {31, 33, 25, 39},// LED 32
  {32, 34, 26, 40}, // LED 33
  {33, 28, 27, 41},// LED 34
  
  {41, 36, 28, 42},// LED 35
  {35, 37, 29, 43}, // LED 36
  {36, 38, 30, 44},// LED 37
  {37, 39, 31, 45}, // LED 38
  {38, 40, 32, 46},// LED 39
  {39, 41, 33, 47}, // LED 40
  {40, 35, 34, 48},// LED 41
  
  {48, 43, 0, 35},// LED 42
  {42, 44, 1, 36}, // LED 43
  {43, 45, 2, 37},// LED 44
  {44, 46, 3, 38}, // LED 45
  {45, 47, 4, 39},// LED 46
  {46, 48, 5, 40}, // LED 47
  {47, 42, 6, 41},// LED 48   
        
};

int j = 0;
int xPin = A2;
int yPin = A1;
int sw = 3;
int position = 0;
int button;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to "off"
  strip.setBrightness(50);
  pinMode(sw, INPUT_PULLUP);
  Serial.begin(9600);
  for (int x = 0; x < NUM_LEDS; x++) {
    fixedLED[x] = 1000;
  }
}




int lastPosition = 0;
int currentPosition = 0;
int currentPositionY = 0;
int lastPositionY = 0;
bool found = false;
int numElements;
int randomLED = 0;
int patternLED[7];
int row; 
int last_row_position;




void loop() {
  currentPosition = analogRead(xPin);
  currentPositionY = analogRead(yPin);
  Serial.println(currentPositionY);
  button = digitalRead(sw);
  row = position / 7 + 1;
  last_row_position = 7 * row - 1;
  
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

  	
    for (int i = 0; i < NUM_LEDS; i++) {
      for (int j = 0; j < NUM_LEDS; j++) {
        if (i == fixedLED[j]) {
          found = true;
          break;
        } else {
          found = false;
        }
      }
      if (!found) {
        strip.setPixelColor(i, 0, 0, 0);
      } else {
        strip.setPixelColor(i, 0, 255, 0);
    	//strip.show();
      }
    }
    //strip.show();
   
    strip.setPixelColor(position, 255, 0, 0);
    //strip.show();
  }
  Serial.println(currentPositionY);
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
   
    for (int i = 0; i < NUM_LEDS; i++) {
      for (int j = 0; j < NUM_LEDS; j++) {
        if (i == fixedLED[j]) {
          found = true;
          break;
        } else {
          found = false;
        }
      }
      if (!found) {
        strip.setPixelColor(i, 0, 0, 0);
        //strip.show();
      } else {
        strip.setPixelColor(i, 0, 255, 0);
    	//strip.show();
      }
    }
   
    strip.setPixelColor(position, 255, 0, 0);
    //strip.show();
  }

  if (button == LOW) {
    fixedLED[j] = position;
    j++;
    pattern(position);
    for (int i = 0; i < 7; i++) {
      if (patternLED[i] == position) {
        strip.setPixelColor(patternLED[i], 255, 0, 0);
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
  
  strip.show();

  delay(100);
  
  lastPosition = currentPosition;
  lastPositionY = currentPositionY;
}




void pattern(int position) {
  numElements = 4;
  
  randomLED = led_connections[position][random(numElements)];
  patternLED[0] = randomLED;
  
  for (int i = 1; i < random(3, 8); i++) {
   randomLED = led_connections[randomLED][random(numElements)];
   patternLED[i] = randomLED; 
  }
}
