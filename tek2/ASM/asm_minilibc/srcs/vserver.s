%ifndef VSERVER
%define VSERVER

section .text
    global vserver:function

vserver:
        mov rax, 236
        syscall
        ret

%endif
