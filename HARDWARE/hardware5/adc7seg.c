#include<stdio.h>
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "Seven_Segment.h"
#include "DrvADC.h"
void seven_seg(uint16_t value)
{
	uint8_t digit;
	digit=value/1000;
	close_seven_segment();
	show_seven_segment(0,digit);
	//add delay here
	value=value-digit*1000;
	digit=value/100;
	close_seven_segment();
	show_seven_segment(1,digit);
	//add delay here
	value=value-digit*100;
	digit=value/10;
	close_seven_segment();
	show_seven_segment(2,digit);
	//add delay here
	value=value-digit*10;
	digit=value;
	close_seven_segment();
	show_seven_segment(3,digit);
	//add delay here
}

int main()
{
	uint16_t value;
	UNLOCKREG();
	DrvSYS_SetOscCtrl(E_SYS_XTL12M,1);
	DrvSYS_SelectHCLKSource(0);
	LOCKREG();
	DrvADC_Open(ADC_SINGLE_END,ADC_SINGLE_OP,0x80,INTERNAL_HCLK,1);
	
	while(1)
	{
		DrvADC_StartConvert();
		while(DrvADC_IsConversionDone()==FALSE);
		value=DrvADC_GetConversionData(7);
		seven_seg(value);
	}
}