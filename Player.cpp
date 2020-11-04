#include "Player.h"

//Player *Player::_exemplar = new Player(Exemplar());

const char* Player::toStr() {
  return name;
}

const char Player::getTypeChar() {
  return Player::_typeChar;
}

Player::Player(Exemplar a): Class(a) {

}

Player::Player(const char* s): Class() {
  if (s[0] == Player::_typeChar) {
    ++s;
    int len = ::strlen(s) + 1;
    name = new char[len];
    ::strcpy(name, s);
  } else {
    Class::errFlag = 'Y';
  }
}

Class *Player::make(const char* s) {
  Class *retval = new Player(s);
  if (Class::errFlag) {
    delete retval;
    retval = 0;
  }
  //Class::errFlag = 0;
  return retval;
}

Class *Player::atPut(Directive key, Class *arg) {
  switch (key) {
    case Class::Directive::Scene:
      return this;
      break;
    default:
      return Class::atPut(key, arg);
      break;
  }
  return this;
}

Class *Player::atGet(Directive key) {
  switch (key) {
    case Class::Directive::Scene:
      return this;
      break;
    default:
      return Class::atGet(key);
      break;
  }
}

Player::~Player() {
  delete[] name;
}
