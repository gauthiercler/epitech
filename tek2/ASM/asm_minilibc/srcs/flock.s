%ifndef FLOCK
%define FLOCK

section .text
    global flock:function

flock:
        mov rax, 73
        syscall
        ret

%endif
