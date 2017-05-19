%ifndef GETTIMEOFDAY
%define GETTIMEOFDAY

section .text
    global gettimeofday:function

gettimeofday:
        mov rax, 96
        syscall
        ret

%endif
