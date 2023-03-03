ORG 0000H
	MOV 	TMOD,#11H ;counter 1, mode 2,C/T=1
				 ;external pulses
	  MOV	TH1,#0		 ;clear TH1
	  SETB	P3.5		 ;make T1 input
AGAIN:	  SETB	TR1		 ;start the counter
BACK:	  MOV	A,TL1		 ;get copy of count TL1
	  MOV	P3,A		 ;display it on port 3
	  JNB	TF1,BACK	 ;keep doing it if TF=0
	  CLR	TR1		 ;stop the counter 1
	  CLR	TF1		 ;make TF=0
	  SJMP	AGAIN		 ;keep doing it
END