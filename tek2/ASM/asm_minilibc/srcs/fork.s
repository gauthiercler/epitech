%ifndef FORK
%define FORK

section .text
    global fork:function

fork:
        mov rax, 57
        syscall
        ret

%endif
