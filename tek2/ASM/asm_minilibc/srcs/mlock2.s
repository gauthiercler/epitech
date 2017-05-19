%ifndef MLOCK2
%define MLOCK2

section .text
    global mlock2:function

mlock2:
        mov rax, 325
        syscall
        ret

%endif
