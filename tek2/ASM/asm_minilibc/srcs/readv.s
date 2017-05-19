%ifndef READV
%define READV

section .text
    global readv:function

readv:
        mov rax, 19
        syscall
        ret

%endif
