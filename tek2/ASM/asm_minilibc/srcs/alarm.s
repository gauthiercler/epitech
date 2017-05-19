%ifndef ALARM
%define ALARM

section .text
    global alarm:function

alarm:
        mov rax, 37
        syscall
        ret

%endif
