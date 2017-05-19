%ifndef GETPID
%define GETPID

section .text
    global getpid:function

getpid:
        mov rax, 39
        syscall
        ret

%endif
