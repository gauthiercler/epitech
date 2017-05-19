%ifndef VMSPLICE
%define VMSPLICE

section .text
    global vmsplice:function

vmsplice:
        mov rax, 278
        syscall
        ret

%endif
