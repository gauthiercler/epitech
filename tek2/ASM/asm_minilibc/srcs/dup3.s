%ifndef DUP3
%define DUP3

section .text
    global dup3:function

dup3:
        mov rax, 292
        syscall
        ret

%endif
