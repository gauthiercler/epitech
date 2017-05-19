%ifndef EVENTFD2
%define EVENTFD2

section .text
    global eventfd2:function

eventfd2:
        mov rax, 290
        syscall
        ret

%endif
