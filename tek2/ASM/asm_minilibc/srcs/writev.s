%ifndef WRITEV
%define WRITEV

section .text
    global writev:function

writev:
        mov rax, 20
        syscall
        ret

%endif
