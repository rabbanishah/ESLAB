2.	Write a C program to toggle a led connected to port C12 and also to buzzer when interrupt is given at port b11.
#include <stdio.h>
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"

void intCallback() {
	DrvGPIO_ClrBit(E_GPC, 12);
	DrvGPIO_ClrBit(E_GPC, 15);
	DrvSYS_Delay(10000);
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 15);
	DrvSYS_Delay(10000);
}

int main() {
	UNLOCKREG();
	SYSCLK->PWRCON.XTL12M_EN = 1;
	SYSCLK->CLKSEL0.HCLK_S = 0;
	LOCKREG();
	
	DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT); //Led is connected to port C12
	DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT); //Buzzer is connected to port B11
	DrvGPIO_Open(E_GPB, 15, E_IO_INPUT); //Interrupt pin is B15
	
	DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, intCallback);
	while(1) {
	}
}
