%ifndef RT_SIGSUSPEND
%define RT_SIGSUSPEND

section .text
    global rt_sigsuspend:function

rt_sigsuspend:
        mov rax, 130
        syscall
        ret

%endif
