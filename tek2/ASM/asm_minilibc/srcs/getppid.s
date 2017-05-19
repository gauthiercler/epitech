%ifndef GETPPID
%define GETPPID

section .text
    global getppid:function

getppid:
        mov rax, 110
        syscall
        ret

%endif
