%ifndef EPOLL_CREATE1
%define EPOLL_CREATE1

section .text
    global epoll_create1:function

epoll_create1:
        mov rax, 291
        syscall
        ret

%endif
