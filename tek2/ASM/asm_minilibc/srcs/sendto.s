%ifndef SENDTO
%define SENDTO

section .text
    global sendto:function

sendto:
        mov rax, 44
        syscall
        ret

%endif
