.model flat,c

.const
	public LsEpsilon
	LsEpsilon real8 1.0e-12

.code
CalcLeastSquaresASM proc
	push ebp
	mov ebp,esp
	sub esp,8

	xor eax,eax
	mov ecx,[ebp+16]
	test ecx,ecx
	jle Done
	mov eax,[ebp+8]
	mov edx,[ebp+12]

	fldz
	fldz
	fldz
	fldz

@@:
	fld real8 ptr [eax]
	fld st(0)
	fld st(0)
	fld real8 ptr [edx]
	; FPU stack: y,x,x,x,sum_x,sum_y,sumxy,sumxx
	fadd st(5),st(0) ; sum_y += y
	; FPU stack: y,x,x,x,sum_x,sum_y = y,sumxy,sumxx
	fmulp ; x * y
	; FPU stack: xy,x,x,sum_x,sum_y,sumxy,sumxx
	faddp st(5),st(0) ; sum_xy += xy
	; FPU stack: x,x,sum_x,sum_y = y,sumxy = xy,sumxx
	fadd st(2),st(0) ; sum_x += x
	; FPU stack: x,sum_x = x,sum_y = y,sumxy = xy,sumxx
	fmulp ; x * x
	; FPU stack: xx,sum_x,sum_y,sumxy,sumxx
	faddp st(4),st(0) ; sum_xx += xx
	; FPU stack: sum_x = x,sum_y = y,sumxy = xy,sumxx = x * x
	add eax,8
	add edx,8
	dec ecx
	jnz @B

	fild dword ptr[ebp+16]
	fmul st(0),st(4)

	fld st(1)
	fld st(0)

	fmulp
	fsubp
	fst real8 ptr[ebp-8]

	fabs
	fld real8 ptr[LsEpsilon]
	fcomip st(0),st(1)
	fstp st(0)
	jae InvalidDenom

	fild dword ptr[ebp+16]

	fmul st(0),st(3)
	fld st(2)
	fld st(2)
	fmulp
	fsubp
	fdiv real8 ptr[ebp-8]
	mov eax,[ebp+20]
	fstp real8 ptr[eax]

	fxch st(3)
	fmulp
	fxch st(2)
	fmulp
	fsubp

	fdiv real8 ptr[ebp-8]
	mov eax,[ebp+24]
	fstp real8 ptr[eax]
	mov eax,1

Done:
	mov esp,ebp
	pop ebp
	ret

InvalidDenom:
	fstp st(0)
	fstp st(0)
	fstp st(0)
	fstp st(0)

	xor eax,eax
	mov esp,ebp
	pop ebp
	ret
CalcLeastSquaresASM endp
end