/*
  OneDigitalTube.h - Library for controlling a 1-digitalTube.
  Created by Ivo Calado<txithihausen@gmail.com>, October 22, 216.
  Released into the public domain.
*/
#ifndef ONEDIGITALTUBE_h
#define ONEDIGITALTUBE_h

#include "Arduino.h"

class OneDigitalTube
{
  public:
    OneDigitalTube();
    void begin(char a, char b, char c, char d, char e, char f, char g, char h, bool enableDebug);
    void begin(char pins[8], bool enableDebug);
    void enableSegment(char s);
    void disableSegment(char s);
    void enableAllSegments();
    void disableAllSegments();
    void enableDP();
    void disableDP();
    void plotNumber(char number);
    
  private:
    char _pins[8];
    char _numbers[10];
    bool _debug;
};

#endif
