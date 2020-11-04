#include "Scene.h"

//Scene *Scene::_exemplar = new Scene(Exemplar());

const char* Scene::toStr() {
  return 0;
}

const char Scene::getTypeChar() {
  return Scene::_typeChar;
}

Scene::Scene(Exemplar a): Class(a) {

}

Class *Scene::make(const char* s) {
  if (s[0] == Scene::_typeChar) {
    return this; //singleton
  }
  return 0;
}

Class *Scene::atPut(Directive key, Class *arg) {
  switch (key) {
    case Class::Directive::Character: //set character under a cursor or return existing
      {
        int i = (::atoi(_ycoord->toStr()) * _xsize) + ::atoi(_xcoord->toStr());
        if (i < 0 && i >= (_xsize * _ysize)) {
          return 0;
        }
        if (_characters[i]) {
          return _characters[i];
        }
        _characters[i] = arg;
        return arg;
      }
      break;
    case Class::Directive::X: //set x coordinate of a cursor within bounds or if new
      //if ((_xsize && (::atoi(arg->toStr()) < _xsize)) || (!_xsize)) {
      _xcoord = arg;
      //} else {
      //  return 0;
      //}
      return 0;
      break;
    case Class::Directive::Y: //set y coordinate of a cursor within bounds or if new
      //if ((_ysize && (::atoi(arg->toStr()) < _ysize)) || (!_ysize)) {
      _ycoord = arg;
      //} else {
      //  return 0;
      //}
      return 0;
      break;
    case Class::Directive::Up: //move pointed character up
      {
        for (int pos = 0; pos < (_xsize * _ysize); pos++) {
          if (_characters[pos] == arg) {
            int newpos = pos - _xsize;
            if (newpos >= 0) {
              if (_characters[newpos]) {
                return _characters[newpos];
              }
              _characters[newpos] = _characters[pos];
              _characters[pos] = 0;
            }
            return arg;
          }
        }
        return 0;
      }
      break;
    case Class::Directive::Down: //move pointed character down
      {
        for (int pos = 0; pos < (_xsize * _ysize); pos++) {
          if (_characters[pos] == arg) {
            int newpos = pos + _xsize;
            if (newpos < _xsize * _ysize) {
              if (_characters[newpos]) {
                return _characters[newpos];
              }
              _characters[newpos] = _characters[pos];
              _characters[pos] = 0;
            }
            return arg;
          }
        }
        return 0;
      }
      break;
    case Class::Directive::Left: //move pointed character left
      {
        for (int pos = 0; pos < (_xsize * _ysize); pos++) {
          if (_characters[pos] == arg) {
            int newpos = pos - 1;
            if (((newpos + 1) % _xsize) != 0) {
              if (_characters[newpos]) {
                return _characters[newpos];
              }
              _characters[newpos] = _characters[pos];
              _characters[pos] = 0;
            }
            return arg;
          }
        }
        return 0;
      }
      break;
    case Class::Directive::Right: //move pointed character right
      {
        for (int pos = 0; pos < (_xsize * _ysize); pos++) {
          if (_characters[pos] == arg) {
            int newpos = pos + 1;
            if ((newpos % _xsize) != 0) {
              if (_characters[newpos]) {
                return _characters[newpos];
              }
              _characters[newpos] = _characters[pos];
              _characters[pos] = 0;
            }
            return arg;
          }
        }
        return 0;
      }
      break;
    default:
      return Class::atPut(key, arg);
      break;
  }
  return this;
}

Class *Scene::atGet(Directive key) {
  switch (key) {
    case Class::Directive::Character: //get the character under the cursor
      {
        int x = ::atoi(_xcoord->toStr());
        int y = ::atoi(_ycoord->toStr());
        return _characters[y * _xsize + x];
        break;
      }
    //    case Class::Directive::Up: //move the cursor up within bounds
    //      {
    //        int x = ::atoi(_xcoord->toStr());
    //        int y = ::atoi(_ycoord->toStr());
    //        return _characters[y * _ysize + x];
    //        break;
    //      }
    //      _ycoord->atGet(Class::Directive::Up);
    //      return this;
    //      break;
    //    case Class::Directive::Down:
    //      _ycoord->atGet(Class::Directive::Up);
    //      return this;
    //      break;
    //    case Class::Directive::Left:
    //      _ycoord->atGet(Class::Directive::Up);
    //      return this;
    //      break;
    //    case Class::Directive::Right:
    //      return this;
    //      break;
    case Class::Directive::X: //get x coordinate of a cursor
      return _xcoord;
      break;
    case Class::Directive::Y: //get y coordinate of a cursor
      return _ycoord;
      break;
    case Class::Directive::Clear: //clear the scene and bounds
      _xsize = 0;
      _ysize = 0;
      //delete _xcoord;
      //delete _ycoord;
      delete[] _characters;
      return this;
      break;
    case Class::Directive::Build: //build the scene and bounds
      _xsize = ::atoi(_xcoord->toStr());
      _ysize = ::atoi(_ycoord->toStr());
      _characters = new Class*[_xsize * _ysize] {};
      return this;
      break;
    case Class::Directive::Draw: //draw scene on the screen
      {
        int xcur = ::atoi(_xcoord->toStr());
        int ycur = ::atoi(_ycoord->toStr());
        for (int y = 0; y < _ysize; y++) {
          for (int x = 0; x < _xsize; x++) {
            if (x == xcur && y == ycur) {
              Class::arduboy.setTextColor(BLACK);
              Class::arduboy.setTextBackground(WHITE);
            }
            if (_characters[y * _xsize + x]) {
              Class::arduboy.print((_characters[y * _xsize + x])->getTypeChar());
            } else {
              Class::arduboy.print(".");
            }
            if (x == xcur && y == ycur) {
              Class::arduboy.setTextColor(WHITE);
              Class::arduboy.setTextBackground(BLACK);
            }
          }
          Class::arduboy.println();
        }
      }
      return 0;
      break;
    default:
      return Class::atGet(key);
      break;
  }
}

Scene::~Scene() {

}
