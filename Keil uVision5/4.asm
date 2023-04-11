;Write an 8051 Assembly level program to Get the Data (your reg.no.) From Port P2 and Send it to Port P3 continuously, 
;while an interrupt will do the following: Timer 0 will toggle the P2.1 bit every 100 microseconds. 
ORG 0000H
	MOV DPTR, #200H
	MOV R0, #0
	LJMP MAIN
	ORG 000BH
		CPL P2.1
		RETI
		ORG 0030H
			MAIN: MOV TMOD, #02H
			MOV TH0, #-92
			MOV IE, #10000010B
			SETB TR0
			BACK: CLR A
			MOVC A, @A+DPTR
			MOV P2, A
			MOV A, P2
			MOV P3, A
			INC DPTR
			INC R0
			CJNE R0, #9,  BACK
			MOV DPTR, #200H
			SJMP BACK
	ORG 200H
		MYDATA: DB "21BCE2067"
END