%ifndef FACCESSAT
%define FACCESSAT

section .text
    global faccessat:function

faccessat:
        mov rax, 269
        syscall
        ret

%endif
