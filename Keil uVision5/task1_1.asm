// Write and assemble a program to load values into each of registers R0 - R4 and then push each of these registers onto the stack.
// Single-step the program, and examine the stack and the SP register after the execution of each instruction.
ORG 0000H
	MOV R1, #35H
	MOV R2, #45H
	MOV R3, #55H
	MOV R4, #65H
	PUSH 0
	PUSH 1
	PUSH 2
	PUSH 3
	PUSH 4
END