%ifndef SETHOSTNAME
%define SETHOSTNAME

section .text
    global sethostname:function

sethostname:
        mov rax, 170
        syscall
        ret

%endif
