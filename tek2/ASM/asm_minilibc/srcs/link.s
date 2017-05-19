%ifndef LINK
%define LINK

section .text
    global link:function

link:
        mov rax, 86
        syscall
        ret

%endif
