%ifndef STRCASECMP
%define STRCASECMP

section 		.text

	global 		strcasecmp:function
	extern 		tolower

strcasecmp:

;	push 		rbx 					;Optional
;	push 		r12						;Saving the callee-save registers
;	push 		r13

	xor 		rax, rax				;Sets rax to 0
	xor 		rdx, rdx


loopOnFirstString:

	mov 		al, [rdi + rdx]
	mov 		cl, [rsi + rdx]			;Cmp only accepts one memory operand, so we store the byte pointed at by rsi (second argument) in the first 8bytes (least significant) of rcx

	push 		rdi

	movzx 		rdi, al

;	call tolower WRT ..plt


	mov 		rax, rdi

	cmp 		rax, 65
	jl 			end_lower1

	cmp 		rax, 90
	jg 			end_lower1

	add 		rax, 32


	end_lower1:

	mov 		r8, rax

	movzx 		rdi, cl


;	call tolower WRT ..plt

	mov 		rax, rdi

	cmp 		rax, 65
	jl 			end_lower2

	cmp 		rax, 90
	jg 			end_lower2

	add 		rax, 32


	end_lower2:


	mov 		r9, rax

	pop 	rdi

	cmp 		r8, r9
	jne 		returnDiff 				;If the two characters are different, we return the difference

	cmp 		r8, byte 0				;If the first string is over, we stop and return.
	je 			return 					;It is done after the byte comparison in order to handle the '\0' in case the two strings are of different length

	cmp 		r9, byte 0				;Same thing for the second string.
	je 			return

	inc 		rdx 					;We increment the common string index to get the next character in memory
	jmp 		loopOnFirstString

returnDiff:

	mov 		rax, r8
	sub 		rax, r9 				;We sub the second character to the first in RAX

	jmp 		return

return :

;	pop			r13						;Optional
;	pop			r12						;Getting back the callee-save registers
;	pop			rbx
	ret

%endif