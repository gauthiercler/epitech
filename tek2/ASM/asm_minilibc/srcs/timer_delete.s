%ifndef TIMER_DELETE
%define TIMER_DELETE

section .text
    global timer_delete:function

timer_delete:
        mov rax, 226
        syscall
        ret

%endif
