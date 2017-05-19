%ifndef EPOLL_WAIT
%define EPOLL_WAIT

section .text
    global epoll_wait:function

epoll_wait:
        mov rax, 232
        syscall
        ret

%endif
