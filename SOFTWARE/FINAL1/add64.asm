	PRESERVE8
	THUMB
	AREA |.text|, CODE , READONLY
	EXPORT __main
__main
	LDR R0,=0XF0000001
	LDR R1,=0X00000001
	LDR R2,=0X10000000
	LDR R3,=0X00000000
	ADDS R0,R0,R2
	ADCS R1,R1,R3
	
	NOP
	END
	