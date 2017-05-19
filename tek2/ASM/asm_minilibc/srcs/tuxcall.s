%ifndef TUXCALL
%define TUXCALL

section .text
    global tuxcall:function

tuxcall:
        mov rax, 184
        syscall
        ret

%endif
