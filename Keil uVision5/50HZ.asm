ORG 0000H
	MOV TMOD, #10H
	AGAIN: MOV TL1, #67H
	MOV TH1, #0FCH
	SETB TR1
	BACK: JNB TF1, BACK
	CLR TR1
	CPL P1.0
	CLR TF1
	SJMP AGAIN
END