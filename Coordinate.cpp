#include "Coordinate.h"

//Coordinate *Coordinate::_exemplar = new Coordinate(Exemplar());

const char* Coordinate::toStr() {
  return value;
}

const char Coordinate::getTypeChar() {
  return Coordinate::_typeChar;
}

Coordinate::Coordinate(Exemplar a): Class(a) {

}

Coordinate::Coordinate(const char* s): Class() {
  if (s[0] == Coordinate::_typeChar) {
    int len = ::strlen(++s) + 1;
    value = new char[len];
    ::strcpy(value, s);
    int i = ::atoi(value);
    if (!i) {
      Class::errFlag = 'Y';
    }
  } else {
    Class::errFlag = 'Y';
  }
}

Class *Coordinate::make(const char* s) {
  Class *retval = new Coordinate(s);
  if (Class::errFlag) {
    delete retval;
    retval = 0;
  }
  return retval;
}

Class *Coordinate::atPut(Directive key, Class *arg) {
  return Class::atPut(key, arg);
}

Class *Coordinate::atGet(Directive key) {
  return Class::atGet(key);
}

Coordinate::~Coordinate() {
  delete[] value;
}
