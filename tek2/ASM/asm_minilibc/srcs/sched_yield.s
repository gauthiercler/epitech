%ifndef SCHED_YIELD
%define SCHED_YIELD

section .text
    global sched_yield:function

sched_yield:
        mov rax, 24
        syscall
        ret

%endif
