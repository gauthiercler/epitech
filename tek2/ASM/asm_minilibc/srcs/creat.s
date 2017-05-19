%ifndef CREAT
%define CREAT

section .text
    global creat:function

creat:
        mov rax, 85
        syscall
        ret

%endif
