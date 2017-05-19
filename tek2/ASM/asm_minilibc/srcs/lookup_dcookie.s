%ifndef LOOKUP_DCOOKIE
%define LOOKUP_DCOOKIE

section .text
    global lookup_dcookie:function

lookup_dcookie:
        mov rax, 212
        syscall
        ret

%endif
