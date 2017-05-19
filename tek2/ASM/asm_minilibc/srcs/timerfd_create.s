%ifndef TIMERFD_CREATE
%define TIMERFD_CREATE

section .text
    global timerfd_create:function

timerfd_create:
        mov rax, 283
        syscall
        ret

%endif
