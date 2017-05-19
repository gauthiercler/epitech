%ifndef DUP2
%define DUP2

section .text
    global dup2:function

dup2:
        mov rax, 33
        syscall
        ret

%endif
