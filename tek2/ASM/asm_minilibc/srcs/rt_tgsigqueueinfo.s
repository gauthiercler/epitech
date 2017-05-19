%ifndef RT_TGSIGQUEUEINFO
%define RT_TGSIGQUEUEINFO

section .text
    global rt_tgsigqueueinfo:function

rt_tgsigqueueinfo:
        mov rax, 297
        syscall
        ret

%endif
