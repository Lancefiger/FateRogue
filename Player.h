#pragma once

#include "Class.h"
#include <Arduino.h>

class Player : public Class {
  public:
    Player(Exemplar a);
    Player(const char* s);
    ~Player();
    Class *atPut(Directive key, Class *arg);
    Class *atGet(Directive key);
    Class *make(const char* s);
    const char* toStr();
    const char getTypeChar();
  private:
    //static Player *_exemplar;
    char* name;
    static const char _typeChar = 0x01;
};
