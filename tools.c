
#include "asmlib.h"

void exit0(int status){
  inline_exit0(status);
}
 
void write0(char* msg, unsigned long len) {
  inline_write0(msg, len);
}

void print_num(long num, char sep) {
  inline_print_num(num, sep);
}

void print_array(long *arr, long size) {
  inline_print_array(arr, size);
}

void print_stack(long size){
  inline_print_stack(size);
}
