%ifndef PREADV
%define PREADV

section .text
    global preadv:function

preadv:
        mov rax, 295
        syscall
        ret

%endif
