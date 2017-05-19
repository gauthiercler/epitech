%ifndef CHROOT
%define CHROOT

section .text
    global chroot:function

chroot:
        mov rax, 161
        syscall
        ret

%endif
