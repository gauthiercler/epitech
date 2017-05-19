%ifndef LISTEN
%define LISTEN

section .text
    global listen:function

listen:
        mov rax, 50
        syscall
        ret

%endif
