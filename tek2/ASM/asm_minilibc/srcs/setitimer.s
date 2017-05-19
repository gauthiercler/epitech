%ifndef SETITIMER
%define SETITIMER

section .text
    global setitimer:function

setitimer:
        mov rax, 38
        syscall
        ret

%endif
