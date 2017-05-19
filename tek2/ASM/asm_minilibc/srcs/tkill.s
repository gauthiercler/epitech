%ifndef TKILL
%define TKILL

section .text
    global tkill:function

tkill:
        mov rax, 200
        syscall
        ret

%endif
