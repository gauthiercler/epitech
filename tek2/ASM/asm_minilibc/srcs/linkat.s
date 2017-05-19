%ifndef LINKAT
%define LINKAT

section .text
    global linkat:function

linkat:
        mov rax, 265
        syscall
        ret

%endif
