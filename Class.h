#pragma once

#include "Exemplar.h"
#include <Arduboy2.h>

class Class {
  protected:
    static Class *list;
    Class *next;
    static char errFlag;
  public:
    static Arduboy2 arduboy;
    enum Directive {
      Up, Down, Left, Right, Attack, Defend, Overcome, CreateAnAdvantage, Scene, Clear, Build, X, Y, Character, Value, Draw
    };
    static Class *exemplar;
    Class(Exemplar);
    Class();
    virtual ~Class();
    virtual Class *atPut(Directive key, Class *arg);
    virtual Class *atGet(Directive key);
    virtual Class *clone() const;
    virtual Class *make(const char* s);
    virtual const char* toStr();
    virtual const char getTypeChar();
};
