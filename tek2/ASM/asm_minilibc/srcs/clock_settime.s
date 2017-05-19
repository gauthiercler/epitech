%ifndef CLOCK_SETTIME
%define CLOCK_SETTIME

section .text
    global clock_settime:function

clock_settime:
        mov rax, 227
        syscall
        ret

%endif
