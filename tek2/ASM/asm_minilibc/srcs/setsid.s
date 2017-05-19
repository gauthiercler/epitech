%ifndef SETSID
%define SETSID

section .text
    global setsid:function

setsid:
        mov rax, 112
        syscall
        ret

%endif
