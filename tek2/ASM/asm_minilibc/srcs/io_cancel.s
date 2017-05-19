%ifndef IO_CANCEL
%define IO_CANCEL

section .text
    global io_cancel:function

io_cancel:
        mov rax, 210
        syscall
        ret

%endif
