%ifndef STRSTR
%define STRSTR

section 		.text

    global 		strstr:function

strstr:

	xor 		rax, rax
	mov 		r8, rdi
	mov 		r9, rsi
	cmp 		[r9], byte 0
	je 			strstr_no_needle

strstr_compute:

	cmp 		[rdi], byte 0
	je 			strstr_end

	mov 		r8, rdi
	mov 		r9, rsi
	needle_loop:

		cmp 		[r9], byte 0
		je 			needle_found

		mov 		r10b, [r9]
		cmp 		[r8], r10b
		jne 		needle_loop_end

		inc 		r8
		inc 		r9
		jmp 		needle_loop

	needle_loop_end:

	inc 		rdi
	jmp 		strstr_compute

needle_found:

	mov 		rax, rdi
	jmp 		strstr_end

strstr_end:

	ret

strstr_no_needle:
	
	mov rax, rdi
	ret

%endif