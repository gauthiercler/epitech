%ifndef SEMOP
%define SEMOP

section .text
    global semop:function

semop:
        mov rax, 65
        syscall
        ret

%endif
