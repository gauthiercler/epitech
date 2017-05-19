%ifndef SYSFS
%define SYSFS

section .text
    global sysfs:function

sysfs:
        mov rax, 139
        syscall
        ret

%endif
