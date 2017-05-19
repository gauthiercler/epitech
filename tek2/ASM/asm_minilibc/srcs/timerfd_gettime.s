%ifndef TIMERFD_GETTIME
%define TIMERFD_GETTIME

section .text
    global timerfd_gettime:function

timerfd_gettime:
        mov rax, 287
        syscall
        ret

%endif
