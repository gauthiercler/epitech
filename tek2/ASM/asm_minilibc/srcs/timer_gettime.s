%ifndef TIMER_GETTIME
%define TIMER_GETTIME

section .text
    global timer_gettime:function

timer_gettime:
        mov rax, 224
        syscall
        ret

%endif
