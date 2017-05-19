%ifndef MLOCK
%define MLOCK

section .text
    global mlock:function

mlock:
        mov rax, 149
        syscall
        ret

%endif
