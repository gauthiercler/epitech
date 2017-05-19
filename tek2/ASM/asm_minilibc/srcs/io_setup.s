%ifndef IO_SETUP
%define IO_SETUP

section .text
    global io_setup:function

io_setup:
        mov rax, 206
        syscall
        ret

%endif
