%ifndef FCHMODAT
%define FCHMODAT

section .text
    global fchmodat:function

fchmodat:
        mov rax, 268
        syscall
        ret

%endif
