%ifndef CAPGET
%define CAPGET

section .text
    global capget:function

capget:
        mov rax, 125
        syscall
        ret

%endif
