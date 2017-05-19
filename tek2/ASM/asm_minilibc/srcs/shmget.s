%ifndef SHMGET
%define SHMGET

section .text
    global shmget:function

shmget:
        mov rax, 29
        syscall
        ret

%endif
