#include<stdio.h>
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"

int main()
{
	int8_t number;
	UNLOCKREG();
	DrvSYS_Open(48000000);\
	LOCKREG();
	OpenKeyPad();
	DrvGPIO_Open(E_GPB,11,E_IO_OUTPUT);
	DrvGPIO_Open(E_GPC,12,E_IO_OUTPUT);
	while(1)
	{
		number=Scankey();
		if(number==2)
		{	
			DrvGPIO_ClrBit(E_GPC,12);
			DrvSYS_Delay(5000);
			DrvGPIO_SetBit(E_GPC,12);
			DrvSYS_Delay(5000);
		}
		else if(number==3)
		{	
			DrvGPIO_ClrBit(E_GPB,11);
			DrvSYS_Delay(5000);
			DrvGPIO_SetBit(E_GPB,11);
			DrvSYS_Delay(5000);
		}
		
	}
	
}
