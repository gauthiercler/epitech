%ifndef TIMER_CREATE
%define TIMER_CREATE

section .text
    global timer_create:function

timer_create:
        mov rax, 222
        syscall
        ret

%endif
