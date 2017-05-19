%ifndef SCHED_SETATTR
%define SCHED_SETATTR

section .text
    global sched_setattr:function

sched_setattr:
        mov rax, 314
        syscall
        ret

%endif
