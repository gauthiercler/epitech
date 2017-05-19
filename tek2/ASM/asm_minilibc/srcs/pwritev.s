%ifndef PWRITEV
%define PWRITEV

section .text
    global pwritev:function

pwritev:
        mov rax, 296
        syscall
        ret

%endif
