%ifndef MOUNT
%define MOUNT

section .text
    global mount:function

mount:
        mov rax, 165
        syscall
        ret

%endif
