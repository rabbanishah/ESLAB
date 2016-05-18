#include<stdio.h>
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"

void function1()
{
	DrvGPIO_ClrBit(E_GPC,15);
	DrvGPIO_ClrBit(E_GPB,11);
	DrvSYS_Delay(10000);
}

int main()
{
		UNLOCKREG();
		DrvSYS_SetOscCtrl(E_SYS_XTL12M,1);
		DrvSYS_SelectHCLKSource(0);
		LOCKREG();
	
		DrvGPIO_Open(E_GPC,15,E_IO_OUTPUT);
		DrvGPIO_Open(E_GPB,11,E_IO_INPUT);
		DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE,E_MODE_EDGE,function1);
		while(1)
		{
		}
		
}