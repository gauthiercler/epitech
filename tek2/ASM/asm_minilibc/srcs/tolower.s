%ifndef TOLOWER
%define TOLOWER

section 		.text

	global 		tolower:function

tolower:

	mov 		rax, rdi

	cmp 		rax, 65
	jl 			end

	cmp 		rax, 90
	jg 			end

	add 		rax, 32

end:

	ret

%endif