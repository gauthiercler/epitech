%ifndef SCHED_GETATTR
%define SCHED_GETATTR

section .text
    global sched_getattr:function

sched_getattr:
        mov rax, 315
        syscall
        ret

%endif
