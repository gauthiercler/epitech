%ifndef CLOCK_NANOSLEEP
%define CLOCK_NANOSLEEP

section .text
    global clock_nanosleep:function

clock_nanosleep:
        mov rax, 230
        syscall
        ret

%endif
