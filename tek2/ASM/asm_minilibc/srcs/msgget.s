%ifndef MSGGET
%define MSGGET

section .text
    global msgget:function

msgget:
        mov rax, 68
        syscall
        ret

%endif
