%ifndef GET_KERNEL_SYMS
%define GET_KERNEL_SYMS

section .text
    global get_kernel_syms:function

get_kernel_syms:
        mov rax, 177
        syscall
        ret

%endif
