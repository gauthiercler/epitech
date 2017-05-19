%ifndef GETPEERNAME
%define GETPEERNAME

section .text
    global getpeername:function

getpeername:
        mov rax, 52
        syscall
        ret

%endif
