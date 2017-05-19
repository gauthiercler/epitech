%ifndef FANOTIFY_MARK
%define FANOTIFY_MARK

section .text
    global fanotify_mark:function

fanotify_mark:
        mov rax, 301
        syscall
        ret

%endif
