%ifndef OPEN
%define OPEN

section .text
    global open:function

open:
        mov rax, 2
        syscall
        ret

%endif
