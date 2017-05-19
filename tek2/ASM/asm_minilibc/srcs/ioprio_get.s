%ifndef IOPRIO_GET
%define IOPRIO_GET

section .text
    global ioprio_get:function

ioprio_get:
        mov rax, 252
        syscall
        ret

%endif
