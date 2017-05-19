%ifndef GETSOCKOPT
%define GETSOCKOPT

section .text
    global getsockopt:function

getsockopt:
        mov rax, 55
        syscall
        ret

%endif
