#include "Class.h"

Arduboy2 Class::arduboy;
Class *Class::list = 0;
Class *Class::exemplar = new Class(Exemplar());
char Class::errFlag = 0;

Class::Class(Exemplar) {
  next = list;
  list = this;
}

Class *Class::make(const char* s) {
  Class *retval = 0;
  for (Class *a = list; a; a = a->next) {
    if (a != Class::exemplar) {
      if (retval = a->make(s))
        break;
    }
  }
  return retval;
}

Class::Class() {
  next = 0;
  Class::errFlag = 0;
}

Class::~Class() {

}

Class *Class::atPut(Directive key, Class *arg) {
  return 0;
}

Class *Class::atGet(Directive key) {
  return 0;
}

Class *Class::clone() const {
  return 0;
}

const char* Class::toStr() {
  return 0;
}

const char Class::getTypeChar() {
  return 0;
}

//Class *Class::popOut(const char* s) {
//  Class *retval = 0;
//  Class *prev = list;
//  for (Class *a = list; a; prev = a, a = a->next) {
//    if (a != Class::exemplar) {
//      if (retval = a->make(s)) {
//        prev->next = a->next;
//        break;
//      }
//    }
//  }
//  return retval;
//}
