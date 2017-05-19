%ifndef PSELECT6
%define PSELECT6

section .text
    global pselect6:function

pselect6:
        mov rax, 270
        syscall
        ret

%endif
