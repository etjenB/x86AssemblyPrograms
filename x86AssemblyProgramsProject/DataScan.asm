.386
.model flat

.data
;intArray sword 0,0,0,0,4,3,0,-34,-56,7,8
intArray sword 0,0,0,0,0,0,0,0,0

.code
DataScan proc
	mov ebx,OFFSET intArray
	mov ecx,LENGTHOF intArray

	L1:
		cmp WORD PTR[ebx],0
		jnz found
		add ebx,2
		loop L1
		jmp notFound

	found:
		movsx eax,WORD PTR[ebx]
		jmp quit

	notFound:
		mov eax,999999

	quit:
		ret

DataScan endp
end