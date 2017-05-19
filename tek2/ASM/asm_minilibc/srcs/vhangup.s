%ifndef VHANGUP
%define VHANGUP

section .text
    global vhangup:function

vhangup:
        mov rax, 153
        syscall
        ret

%endif
