%ifndef CLONE
%define CLONE

section .text
    global clone:function

clone:
        mov rax, 56
        syscall
        ret

%endif
