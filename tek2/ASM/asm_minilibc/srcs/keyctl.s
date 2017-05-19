%ifndef KEYCTL
%define KEYCTL

section .text
    global keyctl:function

keyctl:
        mov rax, 250
        syscall
        ret

%endif
