%ifndef SENDMMSG
%define SENDMMSG

section .text
    global sendmmsg:function

sendmmsg:
        mov rax, 307
        syscall
        ret

%endif
