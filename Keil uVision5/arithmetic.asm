ORG 0000H
	mov a, #25h		// A=25
	mov b, #12h		// B=12
	Add a,b			// A=A+B
	mov 40h, a		// A value transferred to 40h memory address
	mov a, #25h
	Subb a,b
	mov 41h, a
	mov a, #25h
	Mul ab
	mov 42h, a
	mov 43h, b
	mov a, #25h
	mov b, #12h
	Div ab
	mov 44h, a	// quotient
	mov 45h, b	// remainder
	mov a, #25h
	inc a	// increses A
	mov 46h, a	// stores A value in 46h 
	dec a
	mov 47h, a
END