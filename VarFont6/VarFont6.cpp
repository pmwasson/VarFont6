#include "VarFont6.h"

extern Arduboy2 arduboy;

// Variable width font: width 1 to 5 + space.  Height is 6 pixels.
// Each character uses 4 bytes of program memory.
// For width 5, bits 6&7 of bytes 1-3 are used to store the final column data.
// BYTE | BITS 7&6
// 0    | 00       - Width = 2 - 4. E.g. 'A'.
// 0    | 10       - Width = 1 (final column marker). E.g. '!'.
// 0    | x1       - Width = 5. E.g. '$'.
// 1..3 | 10       - Final column, if byte 0 bits 7&6 == 00
// 1    | aa
// 2    | bb
// 3    | cc       - 5th column = ccbbaa, if byte 0 bit 6 == 1


// Contains ASCII #64 – #95 and #32 – #63.
static const unsigned char font[] PROGMEM =
{
  // #064 Symbol '@' (U+0040 Commercial At). Width 4.
  0x1E,  // ▓▓ ▓░░░░▓
  0x21,  // ▓▓ ░▓▓▓▓░
  0x2D,  // ▓▓ ░▓░░▓░
  0xAE,  // *▓ ░▓░░░▓

  // #065 Letter 'A' (U+0041 Latin Capital Letter A). Width 3.
  0x3E,  // ▓▓ ░░░░░▓
  0x09,  // ▓▓ ▓▓░▓▓░
  0xBE,  // *▓ ░░░░░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #066 Letter 'B' (U+0042 Latin Capital Letter B). Width 3.
  0x3F,  // ▓▓ ░░░░░░
  0x25,  // ▓▓ ░▓▓░▓░
  0x9A,  // *▓ ▓░░▓░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #067 Letter 'C' (U+0043 Latin Capital Letter C). Width 3.
  0x1E,  // ▓▓ ▓░░░░▓
  0x21,  // ▓▓ ░▓▓▓▓░
  0xA1,  // *▓ ░▓▓▓▓░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #068 Letter 'D' (U+0044 Latin Capital Letter D). Width 3.
  0x3F,  // ▓▓ ░░░░░░
  0x21,  // ▓▓ ░▓▓▓▓░
  0x9E,  // *▓ ▓░░░░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #069 Letter 'E' (U+0045 Latin Capital Letter E). Width 3.
  0x3F,  // ▓▓ ░░░░░░
  0x25,  // ▓▓ ░▓▓░▓░
  0xA1,  // *▓ ░▓▓▓▓░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #070 Letter 'F' (U+0046 Latin Capital Letter F). Width 3.
  0x3F,  // ▓▓ ░░░░░░
  0x05,  // ▓▓ ▓▓▓░▓░
  0x81,  // *▓ ▓▓▓▓▓░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #071 Letter 'G' (U+0047 Latin Capital Letter G). Width 4.
  0x1E,  // ▓▓ ▓░░░░▓
  0x21,  // ▓▓ ░▓▓▓▓░
  0x29,  // ▓▓ ░▓░▓▓░
  0x98,  // *▓ ▓░░▓▓▓

  // #072 Letter 'H' (U+0048 Latin Capital Letter H). Width 3.
  0x3F,  // ▓▓ ░░░░░░
  0x04,  // ▓▓ ▓▓▓░▓▓
  0xBF,  // *▓ ░░░░░░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #073 Letter 'I' (U+0049 Latin Capital Letter I). Width 3.
  0x21,  // ▓▓ ░▓▓▓▓░
  0x3F,  // ▓▓ ░░░░░░
  0xA1,  // *▓ ░▓▓▓▓░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #074 Letter 'J' (U+004A Latin Capital Letter J). Width 3.
  0x10,  // ▓▓ ▓░▓▓▓▓
  0x20,  // ▓▓ ░▓▓▓▓▓
  0x9F,  // *▓ ▓░░░░░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #075 Letter 'K' (U+004B Latin Capital Letter K). Width 3.
  0x3F,  // ▓▓ ░░░░░░
  0x04,  // ▓▓ ▓▓▓░▓▓
  0xBB,  // *▓ ░░░▓░░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #076 Letter 'L' (U+004C Latin Capital Letter L). Width 3.
  0x3F,  // ▓▓ ░░░░░░
  0x20,  // ▓▓ ░▓▓▓▓▓
  0xA0,  // *▓ ░▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #077 Letter 'M' (U+004D Latin Capital Letter M). Width 5.
  0x7F,  // ▓* ░░░░░░
  0xC2,  // ░░ ▓▓▓▓░▓
  0xC4,  // ░░ ▓▓▓░▓▓
  0xC2,  // ░░ ▓▓▓▓░▓
         //    ░░░░░░

  // #078 Letter 'N' (U+004E Latin Capital Letter N). Width 4.
  0x3F,  // ▓▓ ░░░░░░
  0x02,  // ▓▓ ▓▓▓▓░▓
  0x04,  // ▓▓ ▓▓▓░▓▓
  0xBF,  // *▓ ░░░░░░

  // #079 Letter 'O' (U+004F Latin Capital Letter O). Width 4.
  0x1E,  // ▓▓ ▓░░░░▓
  0x21,  // ▓▓ ░▓▓▓▓░
  0x21,  // ▓▓ ░▓▓▓▓░
  0x9E,  // *▓ ▓░░░░▓

  // #080 Letter 'P' (U+0050 Latin Capital Letter P). Width 3.
  0x3F,  // ▓▓ ░░░░░░
  0x09,  // ▓▓ ▓▓░▓▓░
  0x86,  // *▓ ▓▓▓░░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #081 Letter 'Q' (U+0051 Latin Capital Letter Q). Width 4.
  0x1E,  // ▓▓ ▓░░░░▓
  0x21,  // ▓▓ ░▓▓▓▓░
  0x11,  // ▓▓ ▓░▓▓▓░
  0xAE,  // *▓ ░▓░░░▓

  // #082 Letter 'R' (U+0052 Latin Capital Letter R). Width 3.
  0x3F,  // ▓▓ ░░░░░░
  0x09,  // ▓▓ ▓▓░▓▓░
  0xB6,  // *▓ ░░▓░░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #083 Letter 'S' (U+0053 Latin Capital Letter S). Width 3.
  0x22,  // ▓▓ ░▓▓▓░▓
  0x25,  // ▓▓ ░▓▓░▓░
  0x99,  // *▓ ▓░░▓▓░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #084 Letter 'T' (U+0054 Latin Capital Letter T). Width 3.
  0x01,  // ▓▓ ▓▓▓▓▓░
  0x3F,  // ▓▓ ░░░░░░
  0x81,  // *▓ ▓▓▓▓▓░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #085 Letter 'U' (U+0055 Latin Capital Letter U). Width 4.
  0x1F,  // ▓▓ ▓░░░░░
  0x20,  // ▓▓ ░▓▓▓▓▓
  0x20,  // ▓▓ ░▓▓▓▓▓
  0x9F,  // *▓ ▓░░░░░

  // #086 Letter 'V' (U+0056 Latin Capital Letter V). Width 3.
  0x0F,  // ▓▓ ▓▓░░░░
  0x30,  // ▓▓ ░░▓▓▓▓
  0x8F,  // *▓ ▓▓░░░░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #087 Letter 'W' (U+0057 Latin Capital Letter W). Width 5.
  0x7F,  // ▓* ░░░░░░
  0xD0,  // ░░ ▓░▓▓▓▓
  0xC8,  // ░░ ▓▓░▓▓▓
  0xD0,  // ░░ ▓░▓▓▓▓
         //    ░░░░░░

  // #088 Letter 'X' (U+0058 Latin Capital Letter X). Width 3.
  0x3B,  // ▓▓ ░░░▓░░
  0x04,  // ▓▓ ▓▓▓░▓▓
  0xBB,  // *▓ ░░░▓░░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #089 Letter 'Y' (U+0059 Latin Capital Letter Y). Width 3.
  0x07,  // ▓▓ ▓▓▓░░░
  0x38,  // ▓▓ ░░░▓▓▓
  0x87,  // *▓ ▓▓▓░░░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #090 Letter 'Z' (U+005A Latin Capital Letter Z). Width 4.
  0x31,  // ▓▓ ░░▓▓▓░
  0x29,  // ▓▓ ░▓░▓▓░
  0x25,  // ▓▓ ░▓▓░▓░
  0xA3,  // *▓ ░▓▓▓░░

  // #091 Symbol '[' (U+005B Left Square Bracket). Width 3.
  0x3F,  // ▓▓ ░░░░░░
  0x21,  // ▓▓ ░▓▓▓▓░
  0xA1,  // *▓ ░▓▓▓▓░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #092 Symbol '\' (U+005C Reverse Solidus). Width 3.
  0x03,  // ▓▓ ▓▓▓▓░░
  0x0C,  // ▓▓ ▓▓░░▓▓
  0xB0,  // *▓ ░░▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #093 Symbol ']' (U+005D Right Square Bracket). Width 3.
  0x21,  // ▓▓ ░▓▓▓▓░
  0x21,  // ▓▓ ░▓▓▓▓░
  0xBF,  // *▓ ░░░░░░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #094 Symbol '^' (U+005E Circumflex Accent). Width 3.
  0x02,  // ▓▓ ▓▓▓▓░▓
  0x01,  // ▓▓ ▓▓▓▓▓░
  0x82,  // *▓ ▓▓▓▓░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #095 Symbol '_' (U+005F Low Line). Width 3.
  0x20,  // ▓▓ ░▓▓▓▓▓
  0x20,  // ▓▓ ░▓▓▓▓▓
  0xA0,  // *▓ ░▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #032 Other  ' ' (U+0020 Space). Width 1.
  0x80,  // *▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #033 Symbol '!' (U+0021 Exclamation Mark). Width 1.
  0xAF,  // *▓ ░▓░░░░
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #034 Symbol '"' (U+0022 Quotation Mark). Width 3.
  0x03,  // ▓▓ ▓▓▓▓░░
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x83,  // *▓ ▓▓▓▓░░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #035 Symbol '#' (U+0023 Number Sign). Width 5.
  0x52,  // ▓* ▓░▓▓░▓
  0xBF,  // ░▓ ░░░░░░
  0x12,  // ▓▓ ▓░▓▓░▓
  0x7F,  // ▓░ ░░░░░░
         //    ▓░▓▓░▓

  // #036 Symbol '$' (U+0024 Dollar Sign).Width 5.
  0x52,  // ▓* ▓░▓▓░▓
  0x55,  // ▓░ ▓░▓░▓░
  0xBF,  // ░▓ ░░░░░░
  0x15,  // ▓▓ ▓░▓░▓░
         //    ▓▓░▓▓░

  // #037 Symbol '%' (U+0025 Percent Sign). Width 3.
  0x31,  // ▓▓ ░░▓▓▓░
  0x0C,  // ▓▓ ▓▓░░▓▓
  0xA3,  // *▓ ░▓▓▓░░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #038 Symbol '&' (U+0026 Ampersand). Width 4.
  0x1A,  // ▓▓ ▓░░▓░▓
  0x25,  // ▓▓ ░▓▓░▓░
  0x1A,  // ▓▓ ▓░░▓░▓
  0xA8,  // *▓ ░▓░▓▓▓

  // #039 Symbol ''' (U+0027 Apostrophe). Width 1.
  0x83,  // *▓ ▓▓▓▓░░
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #040 Symbol '(' (U+0028 Left Parenthesis). Width 2.
  0x1E,  // ▓▓ ▓░░░░▓
  0xA1,  // *▓ ░▓▓▓▓░
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #041 Symbol ')' (U+0029 Right Parenthesis). Width 2.
  0x21,  // ▓▓ ░▓▓▓▓░
  0x9E,  // *▓ ▓░░░░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #042 Symbol '*' (U+002A Asterisk). Width 3.
  0x14,  // ▓▓ ▓░▓░▓▓
  0x08,  // ▓▓ ▓▓░▓▓▓
  0x94,  // *▓ ▓░▓░▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #043 Symbol '+' (U+002B Plus Sign). Width 3.
  0x08,  // ▓▓ ▓▓░▓▓▓
  0x1C,  // ▓▓ ▓░░░▓▓
  0x88,  // *▓ ▓▓░▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #044 Symbol ',' (U+002C Comma). Width 2.
  0x20,  // ▓▓ ░▓▓▓▓▓
  0x90,  // *▓ ▓░▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #045 Symbol '-' (U+002D Hyphen-Minus). Width 3.
  0x08,  // ▓▓ ▓▓░▓▓▓
  0x08,  // ▓▓ ▓▓░▓▓▓
  0x88,  // *▓ ▓▓░▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #046 Symbol '.' (U+002E Full Stop). Width 1.
  0xA0,  // *▓ ░▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #047 Symbol '/' (U+002F Solidus). Width 3.
  0x30,  // ▓▓ ░░▓▓▓▓
  0x0C,  // ▓▓ ▓▓░░▓▓
  0x83,  // *▓ ▓▓▓▓░░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #048 Number '0' (U+0030 Digit Zero). Width 3.
  0x1E,  // ▓▓ ▓░░░░▓
  0x21,  // ▓▓ ░▓▓▓▓░
  0x9E,  // *▓ ▓░░░░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #049 Number '1' (U+0031 Digit One). Width 1.
  0xBF,  // *▓ ░░░░░░
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #050 Number '2' (U+0032 Digit Two). Width 3.
  0x32,  // ▓▓ ░░▓▓░▓
  0x29,  // ▓▓ ░▓░▓▓░
  0xA6,  // *▓ ░▓▓░░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #051 Number '3' (U+0033 Digit Three). Width 3.
  0x21,  // ▓▓ ░▓▓▓▓░
  0x25,  // ▓▓ ░▓▓░▓░
  0x9A,  // *▓ ▓░░▓░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #052 Number '4' (U+0034 Digit Four). Width 4.
  0x0F,  // ▓▓ ▓▓░░░░
  0x08,  // ▓▓ ▓▓░▓▓▓
  0x3F,  // ▓▓ ░░░░░░
  0x88,  // *▓ ▓▓░▓▓▓

  // #053 Number '5' (U+0035 Digit Five). Width 3.
  0x27,  // ▓▓ ░▓▓░░░
  0x25,  // ▓▓ ░▓▓░▓░
  0x99,  // *▓ ▓░░▓▓░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #054 Number '6' (U+0036 Digit Six). Width 3.
  0x1E,  // ▓▓ ▓░░░░▓
  0x25,  // ▓▓ ░▓▓░▓░
  0x98,  // *▓ ▓░░▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #055 Number '7' (U+0037 Digit Seven). Width 3.
  0x01,  // ▓▓ ▓▓▓▓▓░
  0x39,  // ▓▓ ░░░▓▓░
  0x87,  // *▓ ▓▓▓░░░
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #056 Number '8' (U+0038 Digit Eight). Width 3.
  0x1A,  // ▓▓ ▓░░▓░▓
  0x25,  // ▓▓ ░▓▓░▓░
  0x9A,  // *▓ ▓░░▓░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #057 Number '9' (U+0039 Digit Nine). Width 3.
  0x06,  // ▓▓ ▓▓▓░░▓
  0x29,  // ▓▓ ░▓░▓▓░
  0x9E,  // *▓ ▓░░░░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #058 Symbol ':' (U+003A Colon). Width 1.
  0x94,  // *▓ ▓░▓░▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #059 Symbol ';' (U+003B Semicolon). Width 2.
  0x20,  // ▓▓ ░▓▓▓▓▓
  0x94,  // *▓ ▓░▓░▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #060 Symbol '<' (U+003C Less-Than Sign). Width 3.
  0x08,  // ▓▓ ▓▓░▓▓▓
  0x14,  // ▓▓ ▓░▓░▓▓
  0xA2,  // *▓ ░▓▓▓░▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #061 Symbol '=' (U+003D Equals Sign). Width 3.
  0x14,  // ▓▓ ▓░▓░▓▓
  0x14,  // ▓▓ ▓░▓░▓▓
  0x94,  // *▓ ▓░▓░▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #062 Symbol '>' (U+003E Greater-Than Sign). Width 3.
  0x22,  // ▓▓ ░▓▓▓░▓
  0x14,  // ▓▓ ▓░▓░▓▓
  0x88,  // *▓ ▓▓░▓▓▓
  0x00,  // ▓▓ ▓▓▓▓▓▓

  // #063 Symbol '?' (U+003F Question Mark). Width 3.
  0x01,  // ▓▓ ▓▓▓▓▓░
  0x29,  // ▓▓ ░▓░▓▓░
  0x86,  // *▓ ▓▓▓░░▓
  0x00   // ▓▓ ▓▓▓▓▓▓

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
