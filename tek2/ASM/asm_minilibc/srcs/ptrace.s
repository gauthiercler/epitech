%ifndef PTRACE
%define PTRACE

section .text
    global ptrace:function

ptrace:
        mov rax, 101
        syscall
        ret

%endif
