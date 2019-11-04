# VarFont6
Variable width font for Arduboy that is 6 pixels high.

Each character has a width from 1 to 5.  Height is 6 pixels.
Each character uses 4 bytes of memory.
The first 6 bits and pixel data and the upper 2 bits are used to encode the width.
For character of width 5, use bits 6&7 of the last 3 bytes to construct the 5th column of pixel data.

Here is how to intepret bits 6&7 for each byte:

Byte | Bits 7&6 | Description
---- | -------- | ---------------------------------------------
0    | 00       | Character is width 2..4
0    | 10       | Character is width 1 (final byte)
0    | 01       | Character is width 5
1..3 | 10       | For width 2..4 character, marks final column
1    | aa       | bits 1&0 of final column (for width 5)
2    | bb       | bits 2&3 of final column (for width 5)
3    | cc       | bits 4&5 of final column (for width 5), 5th column = ccbbaa

