%ifndef WAIT4
%define WAIT4

section .text
    global wait4:function

wait4:
        mov rax, 61
        syscall
        ret

%endif
