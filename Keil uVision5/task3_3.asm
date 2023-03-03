ORG 0000H  ; Start of the program

; Initialize Counter 1 in Mode 1
MOV TMOD, #10H  ; Counter 1, Mode 1

; Configure Pin T1 as input and Port 3 as output
MOV P3, #0H    ; Set all bits of Port 3 as output
SETB P3.0      ; Set bit 0 of Port 3 high
SETB IT1       ; Enable external interrupt 1
SETB EX1       ; Enable external interrupt 1

; Main program loop
MAIN:
    SJMP MAIN     ; Jump back to the beginning of the loop

; External Interrupt 1 Service Routine
INT1_ISR:
    MOV A, TL1     ; Move the state of TL1 to the accumulator
    MOV P3, A     ; Move the state of TL1 to Port 3
    RETI          ; Return from interrupt
END