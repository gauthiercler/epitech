%ifndef FSYNC
%define FSYNC

section .text
    global fsync:function

fsync:
        mov rax, 74
        syscall
        ret

%endif
