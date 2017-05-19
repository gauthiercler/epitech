%ifndef ARCH_PRCTL
%define ARCH_PRCTL

section .text
    global arch_prctl:function

arch_prctl:
        mov rax, 158
        syscall
        ret

%endif
