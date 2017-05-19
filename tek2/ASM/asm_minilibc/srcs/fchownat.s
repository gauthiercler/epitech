%ifndef FCHOWNAT
%define FCHOWNAT

section .text
    global fchownat:function

fchownat:
        mov rax, 260
        syscall
        ret

%endif
