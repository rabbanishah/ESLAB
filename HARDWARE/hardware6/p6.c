#include <stdio.h>
#include "Driver\DrvADC.h"
#include "LCD_Driver.h"
#include "Driver\DrvSYS.h"

int main() {
	uint16_t value;
	char text[16] = "                ";
	UNLOCKREG();
	SYSCLK->PWRCON.XTL12M_EN = 1;
	SYSCLK->CLKSEL0.HCLK_S = 0;
	LOCKREG();
	Initial_panel();
	clr_all_panel();
	DrvADC_Open(ADC_SINGLE_END, ADC_SINGLE_OP, 0x80, INTERNAL_HCLK, 1);
	while(1) {
		DrvADC_StartConvert();
		while(DrvADC_IsConversionDone() == FALSE);
		value = ADC->ADDR[7].RSLT & 0xFFF;
		sprintf(text, "Value: %d", value);
		print_lcd(1, text);
	}
}