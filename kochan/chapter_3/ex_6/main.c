#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	uint32_t answer, result;
	answer = 100;
	result = answer - 10;
	printf ("The result is %i\n", result + 5);
	return 0;
}
