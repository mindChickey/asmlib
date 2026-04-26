
#include "print_num.h"

inline static
__attribute__((always_inline))
void inline_print_array(long *arr, long size) {
  for (long i = 0; i < size; i++) {
    char sep = (i + 1) % 8 == 0 ? '\n' : '\t';
    inline_print_num(arr[i], sep);
  }
  if (size % 8 != 0) inline_write0("\n", 1);
}

inline static
__attribute__((always_inline))
void inline_print_stack(long size){
  void *stack_ptr;
  #if defined(__x86_64__)
  __asm__("mov %%rsp, %0" : "=r"(stack_ptr));
  #elif defined(__aarch64__)
  __asm__("mov %0, sp" : "=r"(stack_ptr));
  #endif
  inline_print_array((long *)stack_ptr, size);
}
