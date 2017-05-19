%ifndef KCMP
%define KCMP

section .text
    global kcmp:function

kcmp:
        mov rax, 312
        syscall
        ret

%endif
