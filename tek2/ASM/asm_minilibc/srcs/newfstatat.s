%ifndef NEWFSTATAT
%define NEWFSTATAT

section .text
    global newfstatat:function

newfstatat:
        mov rax, 262
        syscall
        ret

%endif
