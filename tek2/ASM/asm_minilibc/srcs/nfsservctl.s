%ifndef NFSSERVCTL
%define NFSSERVCTL

section .text
    global nfsservctl:function

nfsservctl:
        mov rax, 180
        syscall
        ret

%endif
