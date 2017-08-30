#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	
	uint32_t n, i;
	unsigned long long factorial;
	
	printf ("TABLE OF FACTORIALS NUMBERS\n\n");
	printf (" n          n!\n");
	printf ("---	--------\n");
	
	for ( n = 0; n <= 10; ++n ) {
		
		factorial = 1 ;
		for ( i = 1; i <= n; ++i){
			factorial = i*factorial;
		}
		
		printf (" %2i	%8llu\n", n, factorial);
	}


	return 0;
}
