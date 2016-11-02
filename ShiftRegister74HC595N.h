/*
  ShiftRegister74HC595N.h - Library for controlling a 74HC595N shift register.
  Created by Ivo Calado<txithihausen@gmail.com>, November 01, 2016.
  Released into the public domain.
*/
#ifndef SHIFTREGISTER74HC595N_h
#define SHIFTREGISTER74HC595N_h
class ShiftRegister74HC595N {
   public:
      ShiftRegister74HC595N(bool debug = false, int baudRate = 9600);
      void begin(int latchPin, int clockPin, int dataPin, int numberOfRegisters = 1);
      void digitalWrite(int pin, bool value);
      void setValue(int value);	
   private:
	bool _debug;
	int _latchPin;
	int _clockPin;
	int _dataPin;
	int _numberOfRegisters; 
	int _currentState;     
};
#endif
