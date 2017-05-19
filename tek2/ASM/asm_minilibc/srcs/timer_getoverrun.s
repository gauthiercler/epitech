%ifndef TIMER_GETOVERRUN
%define TIMER_GETOVERRUN

section .text
    global timer_getoverrun:function

timer_getoverrun:
        mov rax, 225
        syscall
        ret

%endif
