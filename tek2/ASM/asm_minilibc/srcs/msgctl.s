%ifndef MSGCTL
%define MSGCTL

section .text
    global msgctl:function

msgctl:
        mov rax, 71
        syscall
        ret

%endif
