#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int32_t p, d;
	_Bool isPrime;

	printf ("2 3 ");
	for ( p = 5; p <= 50; p+=2 ) {
		isPrime = 1;
		for ( d = 3; d < p; d+=2 ){
			if ( p % d == 0 )
				isPrime = 0;
		}
		if ( isPrime != 0 )
			printf ("%i ", p);
	}

	printf ("\n");
	return 0;
}
