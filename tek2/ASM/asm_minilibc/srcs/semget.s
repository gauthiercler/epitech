%ifndef SEMGET
%define SEMGET

section .text
    global semget:function

semget:
        mov rax, 64
        syscall
        ret

%endif
