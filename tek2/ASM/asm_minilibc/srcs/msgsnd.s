%ifndef MSGSND
%define MSGSND

section .text
    global msgsnd:function

msgsnd:
        mov rax, 69
        syscall
        ret

%endif
