%ifndef KEXEC_LOAD
%define KEXEC_LOAD

section .text
    global kexec_load:function

kexec_load:
        mov rax, 246
        syscall
        ret

%endif
