%ifndef FUTEX
%define FUTEX

section .text
    global futex:function

futex:
        mov rax, 202
        syscall
        ret

%endif
