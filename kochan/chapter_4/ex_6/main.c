#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	float x = 2.55f;
	
	printf("3*x^3 - 5*x^2 + 6 = %.2f\n", (3*x*x*x - 5*x*x + 6));

	return 0;
}
