%ifndef SWAPOFF
%define SWAPOFF

section .text
    global swapoff:function

swapoff:
        mov rax, 168
        syscall
        ret

%endif
