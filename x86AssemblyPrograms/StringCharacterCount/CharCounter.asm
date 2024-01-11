.model flat,c

.code
CountChar proc
	push ebp
	mov ebp,esp
	push esi

	mov esi,[ebp+8]
	mov cx,[ebp+12]

	xor edx,edx

@@:
	lodsw					;load next char into ax, use lodsb for char because char is 8 bit and wchar_t is 16 bit
	or ax,ax				;test for end of string
	jz @F
	cmp ax,cx
	jne @B
	inc edx
	jmp @B

@@:
	mov eax,edx
	pop esi
	pop ebp
	ret
CountChar endp
end