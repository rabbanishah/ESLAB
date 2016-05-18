#include <stdio.h>
#include "Driver\DrvSYS.h"
#include "LCD_Driver.h"
#include "ScanKey.h"
int main() {
	char text[16];
	int8_t number;
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	
	OpenKeyPad();
	Initial_panel();
	clr_all_panel();
	while(1) {
		number = Scankey();
		sprintf(text, "Number: %d", number);
		print_lcd(1, text);
		DrvSYS_Delay(5000);
	}
}
	