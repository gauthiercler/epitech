%ifndef LCHOWN
%define LCHOWN

section .text
    global lchown:function

lchown:
        mov rax, 94
        syscall
        ret

%endif
