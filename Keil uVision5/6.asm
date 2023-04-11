;Write an 8051 Assembly level program to Get the Data (your reg.no.) From Port P2 and Send it to Port P3, Note: P2 is the input Port and P3 is Output Port.
ORG 0000H
	MOV DPTR, #200H
	MOV R0, #0
	MOV TMOD, #02H
	BACK: CLR A
	MOVC A, @A+DPTR
	MOV P2, A
	MOV A, P2
	MOV P3, A
	INC DPTR
	CJNE R0, #9, BACK
	MOV DPTR, #200H
	SJMP BACK
	
	ORG 200H
		MYDATA: DB "21BCE2067"
END