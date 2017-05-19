%ifndef READLINK
%define READLINK

section .text
    global readlink:function

readlink:
        mov rax, 89
        syscall
        ret

%endif
