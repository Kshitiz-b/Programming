;Assume that RAM locations 40 - 44 have the following values. Write a program to find the sum of the values. At the end of the program,
;register A should contain the low byte and R7 the high byte. All values are in hex.
;40=(7D)	41=(EB)		42=(C5)		43=(5B)		44=(30)
ORG 0000H
	MOV 40H, #07DH
	MOV 41H, #0EBH
	MOV 42H, #0C5H
	MOV 43H, #05BH
	MOV 44H, #30H
	
	MOV R0, #40H
	MOV R2, #5
	CLR A
	MOV R7, A
	LOOP: 
		ADD A, @R0
		JNC NEXT
		INC R7
		NEXT:
			INC R0
			DJNZ R2, LOOP
END