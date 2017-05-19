%ifndef GETRUSAGE
%define GETRUSAGE

section .text
    global getrusage:function

getrusage:
        mov rax, 98
        syscall
        ret

%endif
