#include <stdio.h>
#include <stdint.h>

uint32_t roundOFF(uint32_t i, uint32_t j){
	uint32_t x = i;
	uint32_t y = j;
	return (i + j) - x%y;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	printf("round of 256 and 7 = %i\n", roundOFF(256,7) );
	printf("round of 365 and 7 = %i\n", roundOFF(365,7) );
	printf("round of 12258, 23 = %i\n", roundOFF(12258,23) );
	printf("round of 996 and 4 = %i\n", roundOFF(996,4) );
	return 0;
}
