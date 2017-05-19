%ifndef SETPRIORITY
%define SETPRIORITY

section .text
    global setpriority:function

setpriority:
        mov rax, 141
        syscall
        ret

%endif
