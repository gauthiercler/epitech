%ifndef MREMAP
%define MREMAP

section .text
    global mremap:function

mremap:
        mov rax, 25
        syscall
        ret

%endif
