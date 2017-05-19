%ifndef REBOOT
%define REBOOT

section .text
    global reboot:function

reboot:
        mov rax, 169
        syscall
        ret

%endif
