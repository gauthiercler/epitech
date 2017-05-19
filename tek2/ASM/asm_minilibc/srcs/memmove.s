%ifndef MEMMOVE
%define MEMMOVE

section			.text

	global 		memmove:function

memmove:

memmove_compute:

	mov 		rax, rdi
	
	mov 		r8, rdi
	sub 		r8, rsi
	cmp 		r8, 0
	jge 		memmove_rightx

	xor 		r8, r8
	memmove_left:

		cmp 	r8, rdx
		je 	memmove_end

		mov 	r9b, [rsi + r8]
		mov 	[rdi + r8], r9b

		inc 	r8
		jmp 	memmove_left

	memmove_rightx:

	dec 		rdx
	memmove_right:

		cmp 	rdx, -1
		je		memmove_end

		mov 	r9b, [rsi + rdx]
		mov 	[rdi + rdx], r9b
		
		dec 	rdx
		jmp 	memmove_right


memmove_end:

	ret

%endif