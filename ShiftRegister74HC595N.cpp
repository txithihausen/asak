#include <Arduino.h>
#include <ShiftRegister74HC595N.h>

ShiftRegister74HC595N::ShiftRegister74HC595N(bool debug, int baudRate) : _debug(debug) {
	if(_debug) {
		Serial.begin(baudRate);
		Serial.println("Starting ShiftRegister module...");
	}		
}

void ShiftRegister74HC595N::begin(int latchPin, int clockPin, int dataPin, int numberOfRegisters) {
   _latchPin = latchPin;
   _clockPin = clockPin;
   _dataPin = dataPin;
   pinMode(_latchPin, OUTPUT);
   pinMode(_clockPin, OUTPUT);  
   pinMode(_dataPin, OUTPUT);     
   _numberOfRegisters = numberOfRegisters;
}


void ShiftRegister74HC595N::digitalWrite(int pin, bool value) {
	if(pin < 0 || pin >= 8*_numberOfRegisters) {
		if(_debug) 
			Serial.println("ShiftRegister74HC595N::digitalWrite => invalid pin");
		return;
	}
	int number = _currentState;
	number ^= (-value ^ _currentState) & (1 << pin);    
	setValue(number);
}

void ShiftRegister74HC595N::setValue(int value) {
	::digitalWrite(_latchPin, LOW);
	for(byte i = 0; i<_numberOfRegisters*8; i++) {
		::digitalWrite(_clockPin, LOW);   
		boolean pinState = (value>>i)&1;
		::digitalWrite(_dataPin, pinState);             
		::digitalWrite(_clockPin, HIGH);        
	}
	::digitalWrite(_clockPin, LOW);           
	::digitalWrite(_latchPin, HIGH);     
	_currentState = value;
}

