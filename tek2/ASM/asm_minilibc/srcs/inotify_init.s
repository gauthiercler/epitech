%ifndef INOTIFY_INIT
%define INOTIFY_INIT

section .text
    global inotify_init:function

inotify_init:
        mov rax, 253
        syscall
        ret

%endif
