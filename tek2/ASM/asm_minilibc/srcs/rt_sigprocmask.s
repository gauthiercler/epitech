%ifndef RT_SIGPROCMASK
%define RT_SIGPROCMASK

section .text
    global rt_sigprocmask:function

rt_sigprocmask:
        mov rax, 14
        syscall
        ret

%endif
