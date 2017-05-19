%ifndef MSGRCV
%define MSGRCV

section .text
    global msgrcv:function

msgrcv:
        mov rax, 70
        syscall
        ret

%endif
