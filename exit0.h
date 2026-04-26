
#ifndef EXIT0_H
#define EXIT0_H 

#if defined(__x86_64__)

inline static
void inline_exit0(int status) {
  register long rax __asm__("rax") = 60;   // sys_exit
  register long rdi __asm__("rdi") = status; // 退出状态码码

  asm volatile("syscall"
               : // 无输出，因为程序已终止
               : "r"(rax), "r"(rdi)
               : "rcx", "r11", "memory"
  );
  
  // 告诉编译器这之后的代码不可达，有助于优化
  __builtin_unreachable();
}

#elif defined(__aarch64__)

inline static
void inline_exit0(int status) {
    register long x8 __asm__("x8") = 93;     // ARM64 下 sys_exit 的编号是 93
    register long x0 __asm__("x0") = status; // 退出状态码

    asm volatile (
        "svc #0"
        : 
        : "r"(x8), "r"(x0)
        : "memory"
    );

    __builtin_unreachable();
}

#endif

#endif