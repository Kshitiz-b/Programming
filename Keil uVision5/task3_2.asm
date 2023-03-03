	ORG	0000H
		MOV	DPTR,#300H		;load look-up table address
		MOV	A,#0FFH		;A=FF
		MOV	P2,A			;configure P1 as input port
BACK:		MOV	A,P2			;get X
		MOVC	A,@A+DPTR		;get X squared from table
		MOV	P3,A
		INC DPTR 			;issue it to P2
		SJMP	BACK			;keep doing it

		ORG	300H
XSQR_TABLE:
		DB	"21BCE2067"
		END
