%ifndef INOTIFY_RM_WATCH
%define INOTIFY_RM_WATCH

section .text
    global inotify_rm_watch:function

inotify_rm_watch:
        mov rax, 255
        syscall
        ret

%endif
