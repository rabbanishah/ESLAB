	PRESERVE8
	THUMB
	AREA |.TEXT|,CODE,READONLY
	EXPORT __main
__main
	LDR R0,=0XABCDEF01
	MOVS R1,R0
	MOVS R2,#15
	MOVS R3,#4
	MOVS R4,#13
	RORS R0,R0,R2
	LSRS R0,R0,R3
	RORS R0,R0,R4
	
	NOP
	END
