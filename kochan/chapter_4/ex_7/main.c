#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	//(3.31 x 10 -8 x 2.01 x 10 -7 ) / (7.16 x 10 -6 + 2.01 x 10 -8 )
	printf("(3.31 x 10 -8 x 2.01 x 10 -7 ) / (7.16 x 10 -6 + 2.01 x 10 -8 ) = %.30f\n", ((3.31e-8 * 2.01e-7 ) / (7.16e-6 + 2.01e-8)) );
	return 0;
}
