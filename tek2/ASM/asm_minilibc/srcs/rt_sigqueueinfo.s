%ifndef RT_SIGQUEUEINFO
%define RT_SIGQUEUEINFO

section .text
    global rt_sigqueueinfo:function

rt_sigqueueinfo:
        mov rax, 129
        syscall
        ret

%endif
