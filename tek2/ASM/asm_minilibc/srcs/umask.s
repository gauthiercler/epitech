%ifndef UMASK
%define UMASK

section .text
    global umask:function

umask:
        mov rax, 95
        syscall
        ret

%endif
