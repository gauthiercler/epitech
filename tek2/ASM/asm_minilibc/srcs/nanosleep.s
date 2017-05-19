%ifndef NANOSLEEP
%define NANOSLEEP

section .text
    global nanosleep:function

nanosleep:
        mov rax, 35
        syscall
        ret

%endif
