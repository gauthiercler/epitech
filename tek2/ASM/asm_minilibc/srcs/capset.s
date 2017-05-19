%ifndef CAPSET
%define CAPSET

section .text
    global capset:function

capset:
        mov rax, 126
        syscall
        ret

%endif
