%ifndef RT_SIGTIMEDWAIT
%define RT_SIGTIMEDWAIT

section .text
    global rt_sigtimedwait:function

rt_sigtimedwait:
        mov rax, 128
        syscall
        ret

%endif
