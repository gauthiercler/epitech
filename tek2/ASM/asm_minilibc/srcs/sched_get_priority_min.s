%ifndef SCHED_GET_PRIORITY_MIN
%define SCHED_GET_PRIORITY_MIN

section .text
    global sched_get_priority_min:function

sched_get_priority_min:
        mov rax, 147
        syscall
        ret

%endif
