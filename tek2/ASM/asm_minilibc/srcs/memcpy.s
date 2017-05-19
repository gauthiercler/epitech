%ifndef MEMCPY
%define MEMCPY

section .text
    global memcpy:function


memcpy:
	mov rax, rdi

memcpy_compute:
	cmp rdx, 0
	je memcpy_end
	mov r9b, [rsi]
	mov [rdi], r9b
	dec rdx
	inc rdi
	inc rsi
	jmp memcpy_compute

memcpy_end:
	ret

%endif