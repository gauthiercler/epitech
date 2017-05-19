%ifndef GETSID
%define GETSID

section .text
    global getsid:function

getsid:
        mov rax, 124
        syscall
        ret

%endif
