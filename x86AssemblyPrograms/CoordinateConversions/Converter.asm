.model flat,c

.const
	DegToRad real8 0.017453229252
	RadToDeg real8 57.2957795131

.code
RectToPolar proc
	push ebp
	mov ebp,esp

	fld real8 ptr[ebp+16]
	fld real8 ptr[ebp+8]

	fpatan
	fmul [RadToDeg]
	mov eax,[ebp+28]
	fstp real8 ptr[eax]

	fld real8 ptr[ebp+8]
	fmul st(0),st(0)
	fld real8 ptr[ebp+16]
	fmul st(0),st(0)

	faddp
	fsqrt

	mov eax,[ebp+24]
	fstp real8 ptr[eax]

	pop ebp
	ret
RectToPolar endp

PolarToRect proc
	push ebp
	mov ebp,esp

	fld real8 ptr[ebp+16]
	fmul [DegToRad]

	fsincos
	fmul real8 ptr[ebp+8]
	mov eax,[ebp+24]
	fstp real8 ptr[eax]

	fmul real8 ptr[ebp+8]
	mov eax,[ebp+28]
	fstp real8 ptr[eax]

	pop ebp
	ret
PolarToRect endp
end