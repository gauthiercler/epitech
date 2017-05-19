%ifndef SCHED_GETPARAM
%define SCHED_GETPARAM

section .text
    global sched_getparam:function

sched_getparam:
        mov rax, 143
        syscall
        ret

%endif
