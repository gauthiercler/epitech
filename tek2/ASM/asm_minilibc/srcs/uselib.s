%ifndef USELIB
%define USELIB

section .text
    global uselib:function

uselib:
        mov rax, 134
        syscall
        ret

%endif
