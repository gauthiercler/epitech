%ifndef PROCESS_VM_WRITEV
%define PROCESS_VM_WRITEV

section .text
    global process_vm_writev:function

process_vm_writev:
        mov rax, 311
        syscall
        ret

%endif
