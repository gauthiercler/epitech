%ifndef STRPBRK
%define STRPBRK

section 		.text

	global 		strpbrk:function

strpbrk:

	mov 		r8, rdi

strpbrk_core:

	xor 		rax, rax

	cmp 		[r8], byte 0
	je 			strpbrk_end

	mov 		r9, rsi
	string_loop:

		cmp 		[r9], byte 0
		je 			string_loop_end

		mov r10b, [r9]
		cmp [r8], r10b
		je return_address

		inc 		r9
		jmp 		string_loop

	string_loop_end:

	inc 		r8
	jmp 		strpbrk_core

return_address:

	mov 		rax, r8
	jmp 		strpbrk_end

strpbrk_end:
	ret

%endif