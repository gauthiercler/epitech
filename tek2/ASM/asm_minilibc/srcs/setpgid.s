%ifndef SETPGID
%define SETPGID

section .text
    global setpgid:function

setpgid:
        mov rax, 109
        syscall
        ret

%endif
