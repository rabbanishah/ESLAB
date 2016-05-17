	PRESERVE8
	THUMB
	AREA |.TEXT|,CODE,READONLY
	EXPORT __main
__main
	MOVS R0,#2
	CMP R0,#3
	BGT default_case
	MOVS R1,#4
	MULS R0,R1,R0
	LDR R2,=branch_table
	LDR R1 ,[R2,R0]
	BX R1
	ALIGN 4
branch_table
	DCD dest0
	DCD dest1
	DCD dest2
	DCD dest3
dest0
	LDR R0,=0xA
	B next
dest1 
	LDR R0,=0xB
	B next
dest2
	LDR R0,=0xC
	B next
dest3
	LDR R0,=0xD
	B next
default_case
	LDR R0,=0x7
	B next
next
	NOP
	END
