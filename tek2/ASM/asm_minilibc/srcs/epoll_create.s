%ifndef EPOLL_CREATE
%define EPOLL_CREATE

section .text
    global epoll_create:function

epoll_create:
        mov rax, 213
        syscall
        ret

%endif
