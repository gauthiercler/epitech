%ifndef LSEEK
%define LSEEK

section .text
    global lseek:function

lseek:
        mov rax, 8
        syscall
        ret

%endif
