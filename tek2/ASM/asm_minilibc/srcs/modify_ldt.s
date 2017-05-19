%ifndef MODIFY_LDT
%define MODIFY_LDT

section .text
    global modify_ldt:function

modify_ldt:
        mov rax, 154
        syscall
        ret

%endif
