%ifndef GETITIMER
%define GETITIMER

section .text
    global getitimer:function

getitimer:
        mov rax, 36
        syscall
        ret

%endif
