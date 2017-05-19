%ifndef IO_GETEVENTS
%define IO_GETEVENTS

section .text
    global io_getevents:function

io_getevents:
        mov rax, 208
        syscall
        ret

%endif
