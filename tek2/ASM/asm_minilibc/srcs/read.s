%ifndef READ
%define READ

section .text
    global read:function

read:
        mov rax, 0
        syscall
        ret

%endif
