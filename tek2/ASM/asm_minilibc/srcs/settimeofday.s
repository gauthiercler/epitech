%ifndef SETTIMEOFDAY
%define SETTIMEOFDAY

section .text
    global settimeofday:function

settimeofday:
        mov rax, 164
        syscall
        ret

%endif
