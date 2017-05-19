%ifndef SHMCTL
%define SHMCTL

section .text
    global shmctl:function

shmctl:
        mov rax, 31
        syscall
        ret

%endif
