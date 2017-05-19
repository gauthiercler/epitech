%ifndef GET_MEMPOLICY
%define GET_MEMPOLICY

section .text
    global get_mempolicy:function

get_mempolicy:
        mov rax, 239
        syscall
        ret

%endif
