%ifndef INOTIFY_INIT1
%define INOTIFY_INIT1

section .text
    global inotify_init1:function

inotify_init1:
        mov rax, 294
        syscall
        ret

%endif
