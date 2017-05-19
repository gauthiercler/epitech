%ifndef SEMTIMEDOP
%define SEMTIMEDOP

section .text
    global semtimedop:function

semtimedop:
        mov rax, 220
        syscall
        ret

%endif
