%ifndef EPOLL_CTL
%define EPOLL_CTL

section .text
    global epoll_ctl:function

epoll_ctl:
        mov rax, 233
        syscall
        ret

%endif
