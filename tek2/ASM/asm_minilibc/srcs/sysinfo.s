%ifndef SYSINFO
%define SYSINFO

section .text
    global sysinfo:function

sysinfo:
        mov rax, 99
        syscall
        ret

%endif
