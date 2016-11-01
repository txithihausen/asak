#include <Arduino.h>
#include <OneDigitalTube.h>

OneDigitalTube::OneDigitalTube() {
	//Here we set the leds of each digit
	_numbers[0] = 63; // 00111111
	_numbers[1] = 6;  // 00000110	
	_numbers[2] = 91; // 01011011	
	_numbers[3] = 79; // 01001111	
	_numbers[4] = 102;// 01100110	
	_numbers[5] = 109;// 01101101	
	_numbers[6] = 125;// 01111101	
	_numbers[7] = 7;  // 00000111	
	_numbers[8] = 127;// 01111111	
	_numbers[9] = 111;// 01101111	
}

void OneDigitalTube::begin(char a, char b, char c, char d, char e, char f, char g, char h, bool enableDebug) {
	_pins[0] = a;
	_pins[1] = b;
	_pins[2] = c;
	_pins[3] = d;
	_pins[4] = e;
	_pins[5] = f;
	_pins[6] = g;
	_pins[7] = h;
	_debug = enableDebug;

	for (int i=0;i<8;i++)
	{
		pinMode(_pins[i], OUTPUT);
	}	
}

void OneDigitalTube::begin(char pins[8], bool enableDebug) {
	_debug = enableDebug;
	for (int i=0;i<8;i++)
	{
		_pins[i] = pins[i];
		pinMode(_pins[i], OUTPUT);
	}		
}

void OneDigitalTube::enableSegment(char s) {
    digitalWrite(s, HIGH);
}

void OneDigitalTube::disableSegment(char s) {
    digitalWrite(s, LOW);
}

void OneDigitalTube::enableAllSegments() {
   for(int i = 0; i < 8; i++) {
       enableSegment(_pins[i]);
   }
}

void OneDigitalTube::disableAllSegments() {
   for(int i = 0; i < 8; i++) {
       disableSegment(_pins[i]);
   }
}
void OneDigitalTube::enableDP() {
  enableSegment(_pins[7]);
}

void OneDigitalTube::disableDP() {
   disableSegment(_pins[7]);
}

void OneDigitalTube::plotNumber(char number) {

     if(number >=0 && number <=9) {
     	char value = _numbers[number];
     	for(int i = 0; i < 7; i++) {
     		if((value>>i) & 1) {
     			enableSegment(_pins[i]);
     		} else {
     			disableSegment(_pins[i]);
     		}     		
     	}
     } else {
	if(_debug) {
            enableAllSegments();
            delay(300);
            enableAllSegments();
            delay(300);          
            enableAllSegments();
            delay(300);
            enableAllSegments();
            delay(300);
            enableAllSegments();
            delay(300);
            enableAllSegments();
            delay(300);          
          }     
     }
}








