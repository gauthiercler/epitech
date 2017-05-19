%ifndef SYNCFS
%define SYNCFS

section .text
    global syncfs:function

syncfs:
        mov rax, 306
        syscall
        ret

%endif
