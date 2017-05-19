%ifndef TIMERFD_SETTIME
%define TIMERFD_SETTIME

section .text
    global timerfd_settime:function

timerfd_settime:
        mov rax, 286
        syscall
        ret

%endif
