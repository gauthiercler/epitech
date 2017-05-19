%ifndef FCHDIR
%define FCHDIR

section .text
    global fchdir:function

fchdir:
        mov rax, 81
        syscall
        ret

%endif
