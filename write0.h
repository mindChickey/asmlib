
#ifndef WRITE0_H
#define WRITE0_H

#if defined(__x86_64__)
inline static
__attribute__((always_inline))
void inline_write0(char *msg, unsigned long len) {
  register long rax __asm__("rax") = 1;    // sys_write
  register long rdi __asm__("rdi") = 1;    // fd: stdout
  register char *rsi __asm__("rsi") = msg; // buf: msg
  register long rdx __asm__("rdx") = len;  // count: len

  asm volatile("syscall"
               : // 无输出
               : "r"(rax), "r"(rdi), "r"(rsi),
                 "r"(rdx)               // 告诉编译器这些寄存器是输入
               : "rcx", "r11", "memory" // syscall 会修改 rcx 和 r11
  );
}
#elif defined(__aarch64__)
  
inline static
__attribute__((always_inline))
void inline_write0(char* msg, unsigned long len) {
    // ARM64 系统调用约定：x8 是调用号，x0-x2 是前三个参数
    register long x8 __asm__("x8") = 64;   // sys_write 在 ARM64 下的编号是 64
    register long x0 __asm__("x0") = 1;    // fd: stdout
    register char* x1 __asm__("x1") = msg; // buf: msg
    register long x2 __asm__("x2") = len;  // count: len

    asm volatile (
        "svc #0"
        : // 无输出
        : "r"(x8), "r"(x0), "r"(x1), "r"(x2)
        : "memory" // svc 会修改 x0 (返回值)，通常建议声明 memory 保证屏障
    );
}
#endif
#endif