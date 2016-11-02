#include <ShiftRegister74HC595N.h>


int latchPin = 3;
int clockPin = 4; 
int dataPin = 2;
ShiftRegister74HC595N reg(true);
void setup() {
  reg.begin(latchPin, clockPin, dataPin);
}

void loop(){
  for(int i = 0; i < 8; i++) {
    reg.digitalWrite(i, HIGH);
    delay(100);
  }
    delay(500);  
  for(int i = 8; i >= 0; i--) {
    reg.digitalWrite(i, LOW);
    delay(100);
  }  
}


