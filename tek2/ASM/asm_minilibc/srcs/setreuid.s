%ifndef SETREUID
%define SETREUID

section .text
    global setreuid:function

setreuid:
        mov rax, 113
        syscall
        ret

%endif
