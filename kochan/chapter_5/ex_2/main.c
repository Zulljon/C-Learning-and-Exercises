#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	
	int n, power;

	printf ("TABLE OF POWER OF 2 NUMBERS\n\n");
	printf (" n        n^2\n");
	printf ("----   ---------\n");
	power = 0;
	
	for ( n = 1; n <= 10; ++n ) {
		power += n;
		printf (" %2i     %2i\n", n, power);
	}

	return 0;
}
