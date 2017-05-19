%ifndef SYNC_FILE_RANGE
%define SYNC_FILE_RANGE

section .text
    global sync_file_range:function

sync_file_range:
        mov rax, 277
        syscall
        ret

%endif
