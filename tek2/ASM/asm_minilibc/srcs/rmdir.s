%ifndef RMDIR
%define RMDIR

section .text
    global rmdir:function

rmdir:
        mov rax, 84
        syscall
        ret

%endif
