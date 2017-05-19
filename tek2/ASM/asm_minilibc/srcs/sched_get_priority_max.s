%ifndef SCHED_GET_PRIORITY_MAX
%define SCHED_GET_PRIORITY_MAX

section .text
    global sched_get_priority_max:function

sched_get_priority_max:
        mov rax, 146
        syscall
        ret

%endif
