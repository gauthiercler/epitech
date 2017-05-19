%ifndef FALLOCATE
%define FALLOCATE

section .text
    global fallocate:function

fallocate:
        mov rax, 285
        syscall
        ret

%endif
