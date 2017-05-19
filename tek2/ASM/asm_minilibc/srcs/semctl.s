%ifndef SEMCTL
%define SEMCTL

section .text
    global semctl:function

semctl:
        mov rax, 66
        syscall
        ret

%endif
