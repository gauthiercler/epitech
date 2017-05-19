%ifndef EVENTFD
%define EVENTFD

section .text
    global eventfd:function

eventfd:
        mov rax, 284
        syscall
        ret

%endif
