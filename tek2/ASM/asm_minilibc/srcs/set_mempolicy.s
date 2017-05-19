%ifndef SET_MEMPOLICY
%define SET_MEMPOLICY

section .text
    global set_mempolicy:function

set_mempolicy:
        mov rax, 238
        syscall
        ret

%endif
