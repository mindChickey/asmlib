
#ifndef PRINT_NUM_H
#define PRINT_NUM_H

#include "write0.h"

inline static unsigned dump_hex1(char buffer[], unsigned len, long num) {
  unsigned i = len - 1;
  for (; num != 0; num = num >> 4) {
    char d = num & 0xF;
    char c = d < 10 ? d + '0' : d - 10 + 'a';
    buffer[i] = c;
    i--;
  }
  return i + 1;
}

inline static unsigned dump_hex0(char buffer[], unsigned len, long num) {
  if (num == 0) {
    buffer[len - 1] = '0';
    return len - 1;
  } else {
    return dump_hex1(buffer, len, num);
  }
}

inline static unsigned dump_hex(char buffer[], unsigned len, long num) {
  unsigned i = dump_hex0(buffer, len, num);
  buffer[i - 1] = 'x';
  buffer[i - 2] = '0';
  return i - 2;
}

inline static 
void inline_print_num(long num, char sep) {
  char buffer[20];
  unsigned i = dump_hex(buffer, 18, num);
  buffer[18] = sep;
  buffer[19] = '\0';

  char *msg = buffer + i;
  long unsigned len = 20 - i;
  inline_write0(msg, len);
}

#endif