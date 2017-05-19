%ifndef SCHED_SETSCHEDULER
%define SCHED_SETSCHEDULER

section .text
    global sched_setscheduler:function

sched_setscheduler:
        mov rax, 144
        syscall
        ret

%endif
