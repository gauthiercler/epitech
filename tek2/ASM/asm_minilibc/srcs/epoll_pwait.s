%ifndef EPOLL_PWAIT
%define EPOLL_PWAIT

section .text
    global epoll_pwait:function

epoll_pwait:
        mov rax, 281
        syscall
        ret

%endif
