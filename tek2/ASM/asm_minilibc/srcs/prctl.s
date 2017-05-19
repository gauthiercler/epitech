%ifndef PRCTL
%define PRCTL

section .text
    global prctl:function

prctl:
        mov rax, 157
        syscall
        ret

%endif
