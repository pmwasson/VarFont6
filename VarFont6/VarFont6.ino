#include <Arduboy2.h>
#include "VarFont6.h"

Arduboy2 arduboy;
VarFont6 font6;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;
  arduboy.clear();
  font6.setCursor(0,0);
  font6.print(F("VARIABLE WIDTH FONT (6 HIGH):\n\n"));
  font6.print(F(" !\"#$%&'()*+-./0123456789:;<=>?\n"));
  font6.print(F("@ABCDEFGHIJKLMNOPQRSTUVWXYZ\n"));
  font6.print(F("[\\]^_\n\n"));
  font6.print(F("THE QUICK BROWN FOX JUMPS OVER\n"));
  font6.print(F("THE LAZY DOG."));

  // Add a blinking cursor for fun
  if ((arduboy.frameCount & 0x1f) < 16) {
    arduboy.fillRect(font6.cursorX,font6.cursorY,3,6);
  }
  
  arduboy.display();
}
