%ifndef _SYSCTL
%define _SYSCTL

section .text
    global _sysctl:function

_sysctl:
        mov rax, 156
        syscall
        ret

%endif
