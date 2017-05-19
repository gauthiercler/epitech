%ifndef UTIMENSAT
%define UTIMENSAT

section .text
    global utimensat:function

utimensat:
        mov rax, 280
        syscall
        ret

%endif
