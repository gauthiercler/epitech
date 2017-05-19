%ifndef SCHED_SETAFFINITY
%define SCHED_SETAFFINITY

section .text
    global sched_setaffinity:function

sched_setaffinity:
        mov rax, 203
        syscall
        ret

%endif
