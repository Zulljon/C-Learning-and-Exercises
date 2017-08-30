#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	uint32_t n = 1, number, triangularNumber;
	printf ("What triangular number do you want? ");
	scanf ("%i", &number);
	triangularNumber = 0;
	
	while ( n <= number ){
		triangularNumber += n;
		++n;
	}
	
	printf ("Triangular number %i is %i\n", number, triangularNumber);
	return 0;
}
