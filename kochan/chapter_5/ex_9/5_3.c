#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	uint32_t n = 1 , triangularNumber;
	printf ("TABLE OF TRIANGULAR NUMBERS\n\n");
	printf (" n	Sum from 1 to n\n");
	printf ("---	---------------\n");
	triangularNumber = 0;
	
	while ( n <= 10 ) {
		triangularNumber += n;
		printf (" %2i	%i\n", n, triangularNumber);
		++n;
	}
	
	return 0;
}
