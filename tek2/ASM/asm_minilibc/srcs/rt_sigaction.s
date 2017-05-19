%ifndef RT_SIGACTION
%define RT_SIGACTION

section .text
    global rt_sigaction:function

rt_sigaction:
        mov rax, 13
        syscall
        ret

%endif
