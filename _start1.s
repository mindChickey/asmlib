.text
	.globl	_start0                         
// ARM64 指令是 4 字节对齐
	.p2align	2               
	.type	_start0,@function
_start0:
    .cfi_startproc
// 在 ARM64 Linux 中：
// sp 指向 argc
// sp + 8 指向 argv[0]

    ldr     x0, [sp]            // 第一个参数: argc (64位加载到 x0)
    add     x1, sp, #8          // 第二个参数: argv (将 sp+8 的地址给 x1)

// 栈对齐: ARM64 硬件强制要求 SP 在访问内存时必须 16 字节对齐
// 进入 _start 时通常已对齐，这里手动确保对齐（清空低 4 位）
    mov     x2, sp
    and     x2, x2, #~0xf
    mov     sp, x2

    bl      main                // 调用 main, 返回地址存入 lr (x30)
    
// 退出程序
    mov     w0, #0              // 退出状态 status 0 (w0 是 x0 的低32位)
    mov     x8, #93             // exit 系统调用号在 ARM64 中是 93 (x8)
    svc     #0                  // 执行系统调用

.Lfunc_end0:
	.size	_start0, .Lfunc_end0-_start0
	.cfi_endproc

	.ident	"clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits