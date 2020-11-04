#include "LoadOrder.h"

#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char* sbrk(int incr);
#else  // __ARM__
extern char *__brkval;
#endif  // __arm__

int getFreeMemory() {
  char top;
#ifdef __arm__
  return &top - reinterpret_cast<char*>(sbrk(0));
#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
  return &top - __brkval;
#else  // __arm__
  return __brkval ? &top - __brkval : &top - __malloc_heap_start;
#endif  // __arm__
}

Class* scene;
Class* player;
Class* xcur;
Class* ycur;

void setup() {
  Class::arduboy.begin();
  Class::arduboy.setFrameRate(15);
  xcur = Class::exemplar->make("C20");
  ycur = Class::exemplar->make("C7");
  scene = Class::exemplar->make("S");
  scene->atPut(Class::Directive::X, xcur);
  scene->atPut(Class::Directive::Y, ycur);
  scene->atGet(Class::Directive::Build);
  delete xcur;
  delete ycur;
  xcur = Class::exemplar->make("C5");
  ycur = Class::exemplar->make("C5");
  scene->atPut(Class::Directive::X, xcur);
  scene->atPut(Class::Directive::Y, ycur);
  player = Class::exemplar->make("\x01Player");
  scene->atPut(Class::Directive::Character, player);
}

void loop() {
  if (!(Class::arduboy.nextFrame()))
    return;
  Class::arduboy.pollButtons();
  Class::arduboy.clear();

  scene->atGet(Class::Directive::Draw);

  if (Class::arduboy.justPressed(UP_BUTTON)) {
    if (Class::arduboy.anyPressed(A_BUTTON | B_BUTTON)) {
      scene->atPut(Class::Directive::Down, player);
    } else {
      scene->atPut(Class::Directive::Up, player);
    }
  }
  if (Class::arduboy.justPressed(DOWN_BUTTON)) {
    scene->atPut(Class::Directive::Down, player);
  }
  if (Class::arduboy.justPressed(LEFT_BUTTON)) {
    scene->atPut(Class::Directive::Left, player);
  }
  if (Class::arduboy.justPressed(RIGHT_BUTTON)) {
    scene->atPut(Class::Directive::Right, player);
  }

  Class::arduboy.print(getFreeMemory());
  Class::arduboy.println();

  Class::arduboy.display();
}
