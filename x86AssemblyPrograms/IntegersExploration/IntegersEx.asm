.386
.model flat,c

extern GlobalChar:byte
extern GlobalShort:word
extern GlobalInt:dword
extern GlobalLongLong:qword

.code
IntegerAddition proc
	push ebp
	mov ebp,esp

;GlobalChar+=a
	mov al,[ebp+8]
	add [GlobalChar],al

;GlobalShort+=b
	mov ax,[ebp+12]
	add [GlobalShort],ax

;GlobalInt+=c
	mov eax,[ebp+16]
	add [GlobalInt],eax

;GlobalLongLong
	mov eax,[ebp+20]
	mov edx,[ebp+24]
	add dword ptr[GlobalLongLong],eax
	adc dword ptr[GlobalLongLong+4],edx

	pop ebp

	ret
IntegerAddition endp
end