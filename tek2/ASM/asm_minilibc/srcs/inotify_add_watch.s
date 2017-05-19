%ifndef INOTIFY_ADD_WATCH
%define INOTIFY_ADD_WATCH

section .text
    global inotify_add_watch:function

inotify_add_watch:
        mov rax, 254
        syscall
        ret

%endif
