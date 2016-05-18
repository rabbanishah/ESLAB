#include <stdio.h>
#include "Driver\DrvSYS.h"
#include "seven_segment.h"
void seg_display(uint16_t value) {
	int8_t digit;
	digit = value / 1000;
	close_seven_segment();
	show_seven_segment(3, digit);
	DrvSYS_Delay(5000);
	
	value = value - digit * 1000;
	digit = value / 100;
	close_seven_segment();
	show_seven_segment(2, digit);
	DrvSYS_Delay(5000);
	
	value = value - digit * 100;
	digit = value / 10;
	close_seven_segment();
	show_seven_segment(1, digit);
	DrvSYS_Delay(5000);
	
	value = value - digit * 10;
	digit = value;
	close_seven_segment();
	show_seven_segment(0, digit);
	DrvSYS_Delay(5000);
}
int main() {
	uint16_t value = 0;
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	while(value < 9999) {
		seg_display(value);
		DrvSYS_Delay(5000);
		value++;
	}
}