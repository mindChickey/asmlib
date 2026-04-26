	.text
	.file	"_start0.c"
	.globl	_start0                         # -- Begin function _start0
	.p2align	4, 0x90
	.type	_start0,@function
_start0:
    .cfi_startproc
    # %bb.0:
    movq (%rsp), %rdi         # 第一个参数: argc (从栈顶读取)
    leaq 8(%rsp), %rsi        # 第二个参数: argv (指向 argv[0])

    movq %rdi, %rcx
    addq $1, %rcx
    salq $3, %rcx
    leaq (%rsi,%rcx), %rdx    # envp = argv + (argc+1) * 8

    # 栈对齐: call 前确保 rsp 是 16 字节对齐
    # 由于进入 _start 时 rsp 对齐，经过 push 等操作可能偏移
    # 这里简单处理：在调用前对齐
    andq $-16, %rsp           
    call main
    
    # 退出程序
    movl $60, %eax            # exit syscall number
    xorl %edi, %edi           # status 0
    syscall

	#NO_APP
.Lfunc_end0:
	.size	_start0, .Lfunc_end0-_start0
	.cfi_endproc
                                        # -- End function

	.ident	"clang version 15.0.7 (https://github.com/llvm/llvm-project.git d8a53d205df58c5fe4baf73198230b84404098ca)"
	.section	".note.GNU-stack","",@progbits
