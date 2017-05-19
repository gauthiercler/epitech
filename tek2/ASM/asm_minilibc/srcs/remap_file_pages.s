%ifndef REMAP_FILE_PAGES
%define REMAP_FILE_PAGES

section .text
    global remap_file_pages:function

remap_file_pages:
        mov rax, 216
        syscall
        ret

%endif
