#pragma once

#include "Class.h"
#include <Arduino.h>

class Coordinate : public Class {
    friend Class *Class::make(const char* s);
  public:
    Class *atPut(Directive key, Class *arg);
    Class *atGet(Directive key);
    const char* toStr();
    const char getTypeChar();
    ~Coordinate();
    Coordinate(Exemplar a);
  private:
    Coordinate(const char* s);
    //static Coordinate *_exemplar;
    Class *make(const char* s);
    static const char _typeChar = 'C';
    char* value;
};
