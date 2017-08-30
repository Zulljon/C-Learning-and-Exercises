#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	uint32_t n=1, triangularNumber;
	triangularNumber = 0;
	
	while ( n <= 200 ){
		triangularNumber = triangularNumber + n;
		++n;
	}
	
	printf ("The 200th triangular number is %i\n", triangularNumber);
	return 0;
}
