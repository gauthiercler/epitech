%ifndef RT_SIGPENDING
%define RT_SIGPENDING

section .text
    global rt_sigpending:function

rt_sigpending:
        mov rax, 127
        syscall
        ret

%endif
