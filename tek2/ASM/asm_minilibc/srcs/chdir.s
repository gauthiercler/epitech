%ifndef CHDIR
%define CHDIR

section .text
    global chdir:function

chdir:
        mov rax, 80
        syscall
        ret

%endif
