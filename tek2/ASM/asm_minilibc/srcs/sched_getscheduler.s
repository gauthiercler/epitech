%ifndef SCHED_GETSCHEDULER
%define SCHED_GETSCHEDULER

section .text
    global sched_getscheduler:function

sched_getscheduler:
        mov rax, 145
        syscall
        ret

%endif
