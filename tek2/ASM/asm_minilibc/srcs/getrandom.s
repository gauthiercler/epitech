%ifndef GETRANDOM
%define GETRANDOM

section .text
    global getrandom:function

getrandom:
        mov rax, 318
        syscall
        ret

%endif
