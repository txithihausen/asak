#include <ShiftRegister74HC595N.h>


int latchPin = 3;
int clockPin = 4; 
int dataPin = 2;
ShiftRegister74HC595N reg(true);
void setup() {
  reg.begin(latchPin, clockPin, dataPin);
}

void loop(){
  for(int i = 0; i < 256; i++) {
    reg.setValue(i);
    delay(100);
  }

  reg.setValue(0);
  delay(5000);
  
}


