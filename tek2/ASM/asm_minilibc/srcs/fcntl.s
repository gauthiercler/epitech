%ifndef FCNTL
%define FCNTL

section .text
    global fcntl:function

fcntl:
        mov rax, 72
        syscall
        ret

%endif
