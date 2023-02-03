org 0000h
	setb acc.0
	setb acc.1
	clr acc.2
	setb acc.3
	mov c, acc.0
	anl c, acc.1
	orl c, acc.2
	cpl c
	mov acc.7, c
	mov c, acc.2
	cpl c
	anl c, acc.7
	halt: sjmp halt
end