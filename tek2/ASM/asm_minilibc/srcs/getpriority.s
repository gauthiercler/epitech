%ifndef GETPRIORITY
%define GETPRIORITY

section .text
    global getpriority:function

getpriority:
        mov rax, 140
        syscall
        ret

%endif
