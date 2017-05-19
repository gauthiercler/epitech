%ifndef ACCESS
%define ACCESS

section .text
    global access:function

access:
        mov rax, 21
        syscall
        ret

%endif
