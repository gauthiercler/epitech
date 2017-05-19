%ifndef SENDFILE
%define SENDFILE

section .text
    global sendfile:function

sendfile:
        mov rax, 40
        syscall
        ret

%endif
