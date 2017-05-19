%ifndef STRLEN
%define STRLEN

section .text
    global strlen:function


strlen:
	xor rax, rax

strlen_compute:
	cmp [rdi], byte 0
	je strlen_end
	inc rax
	inc rdi
    jmp strlen_compute

strlen_end:
	ret

%endif