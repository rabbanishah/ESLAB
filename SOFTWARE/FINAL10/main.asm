	PRESERVE8
	THUMB
	AREA |.TEXT|,CODE,READONLY
	EXPORT __main
	EXTERN func1
__main
	LDR R0,=0xA
	BL func1
	NOP 
	END