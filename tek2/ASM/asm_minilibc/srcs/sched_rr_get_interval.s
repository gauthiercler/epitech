%ifndef SCHED_RR_GET_INTERVAL
%define SCHED_RR_GET_INTERVAL

section .text
    global sched_rr_get_interval:function

sched_rr_get_interval:
        mov rax, 148
        syscall
        ret

%endif
