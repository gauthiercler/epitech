%ifndef TGKILL
%define TGKILL

section .text
    global tgkill:function

tgkill:
        mov rax, 234
        syscall
        ret

%endif
