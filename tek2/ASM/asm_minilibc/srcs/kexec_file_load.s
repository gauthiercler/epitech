%ifndef KEXEC_FILE_LOAD
%define KEXEC_FILE_LOAD

section .text
    global kexec_file_load:function

kexec_file_load:
        mov rax, 320
        syscall
        ret

%endif
