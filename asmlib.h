
#ifndef ASM_LIB_H
#define ASM_LIB_H

#include "write0.h"
#include "exit0.h"
#include "print_num.h"
#include "print_stack.h"

void exit0(int status);
void write0(char* msg, unsigned long len) ;
void print_num(long num, char sep) ;
void print_array(long *arr, long size) ;
void print_stack(long size);

#endif // ASM_LIB_H