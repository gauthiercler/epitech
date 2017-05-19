%ifndef MEMFD_CREATE
%define MEMFD_CREATE

section .text
    global memfd_create:function

memfd_create:
        mov rax, 319
        syscall
        ret

%endif
