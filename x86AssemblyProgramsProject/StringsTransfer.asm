.386
.model flat

.data
quote byte "This code is amazing, kudos to whoever wrote this",0
message byte SIZEOF quote DUP(0),0

.code
StringsTransfer proc
	mov esi,0
	mov ecx,SIZEOF quote

L:
	mov al,quote[esi]
	mov message[esi],al
	inc esi
	loop L
	
	ret									;no printing, check it in memory :)
StringsTransfer endp
end