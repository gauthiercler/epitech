%ifndef GETPMSG
%define GETPMSG

section .text
    global getpmsg:function

getpmsg:
        mov rax, 181
        syscall
        ret

%endif
