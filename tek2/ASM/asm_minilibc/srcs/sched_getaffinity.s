%ifndef SCHED_GETAFFINITY
%define SCHED_GETAFFINITY

section .text
    global sched_getaffinity:function

sched_getaffinity:
        mov rax, 204
        syscall
        ret

%endif
