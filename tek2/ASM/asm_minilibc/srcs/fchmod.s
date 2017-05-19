%ifndef FCHMOD
%define FCHMOD

section .text
    global fchmod:function

fchmod:
        mov rax, 91
        syscall
        ret

%endif
