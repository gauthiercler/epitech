%ifndef QUOTACTL
%define QUOTACTL

section .text
    global quotactl:function

quotactl:
        mov rax, 179
        syscall
        ret

%endif
