#pragma once

#include "Class.h"
#include <Arduino.h>

class Scene : public Class {
    friend Class *Class::make(const char* s);
  public:
    Class *atPut(Directive key, Class *arg);
    Class *atGet(Directive key);
    const char* toStr();
    const char getTypeChar();
    Scene(Exemplar a);
    ~Scene();
  private:
    //static Scene *_exemplar;
    //Scene(Exemplar a);
    //~Scene();
    Class *make(const char* s);
    static const char _typeChar = 'S';
    Class* _xcoord;
    Class* _ycoord;
    int _xsize;
    int _ysize;
    Class** _characters;
};
