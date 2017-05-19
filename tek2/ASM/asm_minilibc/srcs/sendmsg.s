%ifndef SENDMSG
%define SENDMSG

section .text
    global sendmsg:function

sendmsg:
        mov rax, 46
        syscall
        ret

%endif
