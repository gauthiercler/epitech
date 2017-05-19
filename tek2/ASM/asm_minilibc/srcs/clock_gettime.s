%ifndef CLOCK_GETTIME
%define CLOCK_GETTIME

section .text
    global clock_gettime:function

clock_gettime:
        mov rax, 228
        syscall
        ret

%endif
