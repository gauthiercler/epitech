%ifndef RESTART_SYSCALL
%define RESTART_SYSCALL

section .text
    global restart_syscall:function

restart_syscall:
        mov rax, 219
        syscall
        ret

%endif
