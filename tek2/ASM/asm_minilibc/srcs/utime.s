%ifndef UTIME
%define UTIME

section .text
    global utime:function

utime:
        mov rax, 132
        syscall
        ret

%endif
