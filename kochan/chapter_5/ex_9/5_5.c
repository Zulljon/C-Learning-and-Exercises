#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	uint32_t n, number, triangularNumber, counter = 1;
	
	while ( counter <= 5) {
		printf ("What triangular number do you want? ");
		scanf ("%i", &number);
		triangularNumber = 0;

		n = 1;
		while ( n <= number ){
			triangularNumber += n;
			++n;
		}

		printf ("Triangular number %i is %i\n\n", number, triangularNumber);
		++counter;
	}
	return 0;
}
