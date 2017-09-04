#include <stdio.h>
#include <stdint.h>

uint32_t calculateTriangularNumber (uint32_t n){
	uint32_t i, triangularNumber = 0;
	for ( i = 1; i <= n; ++i ) {
		triangularNumber += i;
	}
	return triangularNumber;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){

	uint32_t number, counter;
	for ( counter = 1; counter <= 5; ++counter ) {
		printf ("What triangular number do you want? ");
		scanf ("%i", &number);
		printf ("Triangular number %i is %i\n\n", number, calculateTriangularNumber(number));
	}

	return 0;
}
