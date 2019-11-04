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
  font6.print("VARIABLE WIDTH FONT (6 HIGH):\n\n");
  font6.print(" !\"#$%&'()*+-./0123456789:;<=>?\n");
  font6.print("@ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
  font6.print("[\\]^_\n\n");
  font6.print("THE QUICK BROWN FOX JUMPS OVER\n");
  font6.print("THE LAZY DOG.\n");
  font6.print("A = (5 * 6 + 17) % 3");
  
  arduboy.display();
}
