#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	
	uint32_t n, number, triangularNumber, counter;

	while (1) {
		printf ("What triangular number do you want? ");
		scanf ("%i", &number);
		triangularNumber = 0;
		for ( n = 1; n <= number; ++n )
			triangularNumber += n;
		printf ("Triangular number %i is %llu\n\n", number, (long long unsigned)triangularNumber);
	}
	
	return 0;
}
