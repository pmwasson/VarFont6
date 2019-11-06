#include "VarFont6.h"

extern Arduboy2 arduboy;

// Variable width font: width 1 to 5 + space.  Height is 6 pixels.
// Each character uses 4 bytes of memory
// For width 5, uses bits 6&7 of each bytes 1-3 to store final column.
// Byte Bits 7&6
// 0    00       - width = 2..4
// 0    10       - width = 1 (final byte)
// 0    x1       - width 5
// 1..3 10       - final column if byte 0, bits 7&6 == 00
// 1    aa
// 2    bb
// 3    cc       - 5th column = ccbbaa if byte 0, bit 6 == 1

static const unsigned char font[] PROGMEM =
{                           // Char : Width
  0x1E, 0x21, 0x2D, 0xAE,   // @ : 4 
  0x3E, 0x09, 0xBE, 0x00,   // A : 3
  0x3F, 0x25, 0x9A, 0x00,   // B : 3 
  0x1E, 0x21, 0xA1, 0x00,   // C : 3
  0x3F, 0x21, 0x9E, 0x00,   // D : 3
  0x3F, 0x25, 0xA1, 0x00,   // E : 3 
  0x3F, 0x05, 0x81, 0x00,   // F : 3
  0x1E, 0x21, 0x29, 0x98,   // G : 4
  0x3F, 0x04, 0xBF, 0x00,   // H : 3
  0x21, 0x3F, 0xA1, 0x00,   // I : 3 
  0x10, 0x20, 0x9F, 0x00,   // J : 3 
  0x3F, 0x04, 0xBB, 0x00,   // K : 3 
  0x3F, 0x20, 0xA0, 0x00,   // L : 3
  0x7F, 0xC2, 0xC4, 0xC2,   // M : 5
  0x3F, 0x02, 0x04, 0xBF,   // N : 4
  0x1E, 0x21, 0x21, 0x9E,   // O : 4
  0x3F, 0x09, 0x86, 0x00,   // P : 3
  0x1E, 0x21, 0x11, 0xAE,   // Q : 4
  0x3F, 0x09, 0xB6, 0x00,   // R : 3
  0x22, 0x25, 0x99, 0x00,   // S : 4
  0x01, 0x3F, 0x81, 0x00,   // T : 3 
  0x1F, 0x20, 0x20, 0x9F,   // U : 4
  0x0F, 0x30, 0x8F, 0x00,   // V : 3
  0x7F, 0xD0, 0xC8, 0xD0,   // W : 5 
  0x3B, 0x04, 0xBB, 0x00,   // X : 3
  0x07, 0x38, 0x87, 0x00,   // Y : 3
  0x31, 0x29, 0x25, 0xA3,   // Z : 4
  0x3F, 0x21, 0xA1, 0x00,   // [ : 3
  0x03, 0x0C, 0xB0, 0x00,   // \ : 3 
  0x21, 0x21, 0xBF, 0x00,   // ] : 3
  0x02, 0x01, 0x82, 0x00,   // ^ : 3
  0x20, 0x20, 0xA0, 0x00,   // _ : 3
  0x80, 0x00, 0x00, 0x00,   // sp: 1
  0xAF, 0x00, 0x00, 0x00,   // ! : 1
  0x03, 0x00, 0x83, 0x00,   // " : 3
  0x52, 0xBF, 0x12, 0x7F,   // # : 5
  0x52, 0x55, 0xBF, 0x15,   // $ : 5 
  0x31, 0x0C, 0xA3, 0x00,   // % : 3
  0x1A, 0x25, 0x1A, 0xA8,   // & : 4
  0x83, 0x00, 0x00, 0x00,   // ' : 1  
  0x1E, 0xA1, 0x00, 0x00,   // ( : 2
  0x21, 0x9E, 0x00, 0x00,   // ) : 2
  0x14, 0x08, 0x94, 0x00,   // * : 3
  0x08, 0x1C, 0x88, 0x00,   // + : 3
  0x20, 0x90, 0x00, 0x00,   // , : 2 
  0x08, 0x08, 0x88, 0x00,   // - : 3 
  0xA0, 0x00, 0x00, 0x00,   // . : 1
  0x30, 0x0C, 0x83, 0x00,   // / : 3
  0x1E, 0x21, 0x9E, 0x00,   // 0 : 3
  0xBF, 0x00, 0x00, 0x00,   // 1 : 1
  0x32, 0x29, 0xA6, 0x00,   // 2 : 3
  0x21, 0x25, 0x9A, 0x00,   // 3 : 3
  0x0F, 0x08, 0x3F, 0x88,   // 4 : 4 
  0x27, 0x25, 0x99, 0x00,   // 5 : 3
  0x1E, 0x25, 0x98, 0x00,   // 6 : 3
  0x01, 0x39, 0x87, 0x00,   // 7 : 3
  0x1A, 0x25, 0x9A, 0x00,   // 8 : 3
  0x06, 0x29, 0x9E, 0x00,   // 9 : 3
  0x94, 0x00, 0x00, 0x00,   // : : 1
  0x20, 0x94, 0x00, 0x00,   // ; : 2
  0x08, 0x14, 0xA2, 0x00,   // < : 3 
  0x14, 0x14, 0x94, 0x00,   // = : 3 
  0x22, 0x14, 0x88, 0x00,   // > : 3
  0x01, 0x29, 0x86, 0x00    // ? : 3
};

size_t VarFont6::write(uint8_t c) {
  if (c == '\n')      { cursorX = baseX; cursorY += lineHeight; }
  else {
    size_t width = printChar(c, cursorX, cursorY);
    cursorX += width + letterSpacing;
  }
  return 1;
}

size_t VarFont6::printChar(char c, int8_t x, int8_t y) {
  // Index into font (map lowercase to uppercase)
  uint8_t fontIndex = (c & ((c < 96) ? 0x3f : 0x1f)) * 4;

  // Y offset
  uint8_t offset = y & 0x7;
  
  // Pointer into screen buffer
  uint16_t screenIndex = WIDTH * (y >> 3) + x;
  
  uint8_t fifthCol = 0;
  bool    useFifth = false;
  
  for (uint8_t i=0 ; i < 5; i++) {
    uint8_t data, column;
    if (i < 4) {
      data = pgm_read_byte(font + fontIndex + i);
      column = data & 0x3f; // 6 bits
      fifthCol = (fifthCol >> 2) | (data & 0xc0); // Save upper bits
      if (i==0) {
        useFifth = (data & fiveWideBit) != 0;
      }
    }
    else {
      data = 0;
      column = fifthCol >> 2;
    }

    if (screenIndex < WIDTH*(HEIGHT>>3))
      if (inverse) {
        arduboy.sBuffer[screenIndex] &= ~(column << offset);      
      } else {
        arduboy.sBuffer[screenIndex] |= column << offset;
      }
    if ((offset > 1) && (screenIndex + 128 < WIDTH*(HEIGHT>>3))) {
      if (inverse) {
        arduboy.sBuffer[screenIndex+128] &= ~(column >> (8 - offset));
      } else {
        arduboy.sBuffer[screenIndex+128] |= column >> (8 - offset);
      } 
    }
    if (!useFifth && ((data & stopBit) != 0)) {
      return i+1; 
    }
    screenIndex++;
  }
  return 5; // max width
}

void VarFont6::setCursor(int8_t x, int8_t y) {
  cursorX = x;
  baseX = x;
  cursorY = y;
}

void VarFont6::setInverse(bool inv) {
  inverse = inv;
}
