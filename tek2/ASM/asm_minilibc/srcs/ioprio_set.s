%ifndef IOPRIO_SET
%define IOPRIO_SET

section .text
    global ioprio_set:function

ioprio_set:
        mov rax, 251
        syscall
        ret

%endif
