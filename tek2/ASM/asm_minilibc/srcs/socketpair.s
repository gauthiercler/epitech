%ifndef SOCKETPAIR
%define SOCKETPAIR

section .text
    global socketpair:function

socketpair:
        mov rax, 53
        syscall
        ret

%endif
