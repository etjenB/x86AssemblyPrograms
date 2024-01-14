.386
.model flat,c

;Surface area of a sphere: 4 * Pi * radius^2
;Volume of a sphere: 4 * Pi * radius^3 / 3 || (4 * Pi * radius^2) * r / 3

.const
r8_4p0 real8 4.0
r8_3p0 real8 3.0

.code
CalcSphereAreaVolume proc
	push ebp
	mov ebp,esp

	xor eax,eax

	fld real8 ptr[ebp+8]				;ST(0) = r (first parameter)
	fldz								;pushes current value from ST(0) to ST(1), loads 0 to ST(0)
	fcomip st(0),st(1)					;compares 0 to r
	fstp st(0)

	jp InvalidParameters				;jump if unordered operands
	ja InvalidParameters				;jump if r < 0

	fld real8 ptr[ebp+8]				;ST(0) = r (first parameter) again
	fld st(0)							;ST(0) = r, ST(1) = r

	fmul st(0),st(0)					;ST(0) = r * r, ST(1) = r

	fldpi								;ST(0) = Pi

	fmul [r8_4p0]							;ST(0) = 4 * Pi
	fmulp								;ST(0) = 4 * Pi * r * r

	mov edx,[ebp+16]
	fst real8 ptr[edx]

	;Volume
	fmulp								;ST(0) = Pi * 4 * r * r * r
	fdiv [r8_3p0]							;ST(0) = Pi * 4 * r * r * r / 3

	mov edx,[ebp+20]
	fstp real8 ptr[edx]

	mov eax,1

InvalidParameters:
	pop ebp
	ret

CalcSphereAreaVolume endp
end