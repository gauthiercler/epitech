%ifndef SETRESUID
%define SETRESUID

section .text
    global setresuid:function

setresuid:
        mov rax, 117
        syscall
        ret

%endif
