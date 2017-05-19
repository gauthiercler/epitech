%ifndef GETPGRP
%define GETPGRP

section .text
    global getpgrp:function

getpgrp:
        mov rax, 111
        syscall
        ret

%endif
