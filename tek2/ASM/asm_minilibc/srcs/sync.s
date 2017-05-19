%ifndef SYNC
%define SYNC

section .text
    global sync:function

sync:
        mov rax, 162
        syscall
        ret

%endif
