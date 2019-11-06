#pragma once
#include <Arduboy2.h>

class VarFont6 : public Print {
  public:
    virtual size_t write(uint8_t); // used by the Arduino Print class
    size_t printChar(char c, int8_t x, int8_t y);
    void setCursor(int8_t x, int8_t y);
    void setInverse(bool inv);
  
    int8_t cursorX = 0;
    int8_t cursorY = 0;
    bool inverse = false;

  private:
    static const uint8_t lineHeight = 7;
    static const uint8_t letterSpacing = 1;
    static const uint8_t stopBit = 0x80;
    static const uint8_t fiveWideBit = 0x40;
    int8_t baseX = 0;
};
