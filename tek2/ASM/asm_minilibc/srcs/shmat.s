%ifndef SHMAT
%define SHMAT

section .text
    global shmat:function

shmat:
        mov rax, 30
        syscall
        ret

%endif
