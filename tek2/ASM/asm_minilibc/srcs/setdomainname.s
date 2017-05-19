%ifndef SETDOMAINNAME
%define SETDOMAINNAME

section .text
    global setdomainname:function

setdomainname:
        mov rax, 171
        syscall
        ret

%endif
