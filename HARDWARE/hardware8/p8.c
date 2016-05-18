use B14 B15
#include <stdio.h>
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "LCD_Driver.h"
#include "Seven_Segment.h"
#include "DrvGPIO.h"

void seg_display() {
	close_seven_segment();
	show_seven_segment(0, 7);
	DrvSYS_Delay(5000);
	
	close_seven_segment();
	show_seven_segment(1, 7);
	DrvSYS_Delay(5000);
}

void displayA() {
	Initial_panel();
	clr_all_panel();
	print_lcd(0, "a");
}
void ab_int_callback(uint32_t a, uint32_t b) {
	if ((a) & 0x01) displayA();
}

void cde_int_callback(uint32_t c, uint32_t d, uint32_t e) {
		if ((c>>15) & 0x01) seg_display();
}

int main() {
	UNLOCKREG();
	SYSCLK->PWRCON.XTL12M_EN = 1;
	SYSCLK->CLKSEL0.HCLK_S = 0;
	LOCKREG();
	DrvGPIO_Open(E_GPA, 0, E_IO_INPUT);
	DrvGPIO_Open(E_GPC, 15, E_IO_INPUT);

	DrvGPIO_EnableInt(E_GPA, 0, E_IO_RISING, E_MODE_EDGE);
	DrvGPIO_EnableInt(E_GPC, 15, E_IO_RISING, E_MODE_EDGE);
	
	DrvGPIO_SetIntCallback(ab_int_callback, cde_int_callback);

}
