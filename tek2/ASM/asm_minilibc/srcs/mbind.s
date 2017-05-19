%ifndef MBIND
%define MBIND

section .text
    global mbind:function

mbind:
        mov rax, 237
        syscall
        ret

%endif
