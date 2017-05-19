%ifndef SETSOCKOPT
%define SETSOCKOPT

section .text
    global setsockopt:function

setsockopt:
        mov rax, 54
        syscall
        ret

%endif
