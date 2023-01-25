org 0000h
	xx: mov r0, #50h
	mov 50h, #25
	mov a, @r0
	jz xx
	inc r0
	mov a, @r0
end