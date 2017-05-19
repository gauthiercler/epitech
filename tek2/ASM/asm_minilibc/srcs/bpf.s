%ifndef BPF
%define BPF

section .text
    global bpf:function

bpf:
        mov rax, 321
        syscall
        ret

%endif
