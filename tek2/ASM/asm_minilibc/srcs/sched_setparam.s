%ifndef SCHED_SETPARAM
%define SCHED_SETPARAM

section .text
    global sched_setparam:function

sched_setparam:
        mov rax, 142
        syscall
        ret

%endif
