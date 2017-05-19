%ifndef RT_SIGRETURN
%define RT_SIGRETURN

section .text
    global rt_sigreturn:function

rt_sigreturn:
        mov rax, 15
        syscall
        ret

%endif
