%ifndef MEMBARRIER
%define MEMBARRIER

section .text
    global membarrier:function

membarrier:
        mov rax, 324
        syscall
        ret

%endif
