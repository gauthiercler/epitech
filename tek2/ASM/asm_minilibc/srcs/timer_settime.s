%ifndef TIMER_SETTIME
%define TIMER_SETTIME

section .text
    global timer_settime:function

timer_settime:
        mov rax, 223
        syscall
        ret

%endif
