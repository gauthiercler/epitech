%ifndef MUNLOCK
%define MUNLOCK

section .text
    global munlock:function

munlock:
        mov rax, 150
        syscall
        ret

%endif
