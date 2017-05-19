%ifndef UMOUNT2
%define UMOUNT2

section .text
    global umount2:function

umount2:
        mov rax, 166
        syscall
        ret

%endif
