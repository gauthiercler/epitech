%ifndef SHMDT
%define SHMDT

section .text
    global shmdt:function

shmdt:
        mov rax, 67
        syscall
        ret

%endif
