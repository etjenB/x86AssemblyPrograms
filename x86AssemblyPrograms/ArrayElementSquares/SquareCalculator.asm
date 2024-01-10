.386
.model flat,c

.code
CalcArraySquaresASM proc
	
	push ebp
	mov ebp, esp
	push ebx
	push esi
	push edi

	mov edi,[ebp+8]
	mov esi,[ebp+12]
	mov ecx,[ebp+16]

	xor eax,eax

	cmp ecx,0
	jle EmptyArray
	shl ecx,2			;multiply by 4, if we had 3 here it would be ecx = ecx * 2^3, multiply by 4 gives us size of array in bytes
	xor ebx,ebx			;ebx = array element offset

@@:
	mov edx,[esi+ebx]	;load next x[i]
	imul edx,edx
	mov [edi+ebx],edx	;saves result to y[i]
	add eax,edx			;updates running sum
	add ebx,4			;update array element offset
	cmp ebx,ecx
	jl @B

EmptyArray:
	pop edi
	pop esi
	pop ebx
	pop ebp
	ret
CalcArraySquaresASM endp
end