#include <stdio.h>
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"

int main() {
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	DrvGPIO_Open(E_GPA, 12, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPA, 13, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPA, 14, E_IO_OUTPUT);
	
	while(1) {
		DrvGPIO_SetBit(E_GPA, 12);
		DrvGPIO_SetBit(E_GPA, 13);
		DrvGPIO_SetBit(E_GPA, 14);
		DrvSYS_Delay(5000);
		DrvGPIO_ClrBit(E_GPA, 12);
		DrvGPIO_ClrBit(E_GPA, 13);
		DrvGPIO_ClrBit(E_GPA, 14);
		DrvSYS_Delay(5000);
	}
}