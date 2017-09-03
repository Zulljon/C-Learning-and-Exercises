// Program to generate the first 15 Fibonacci numbers witout array
#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){

		int Fibonacci[3], i;
		Fibonacci[0] = 0;	// by definition
		Fibonacci[1] = 1;	// ditto

		printf("%i\n%i\n",Fibonacci[0] , Fibonacci[1] );

		for ( i = 2; i < 15; ++i ){
			Fibonacci[2] = Fibonacci[1] + Fibonacci[0];
			printf ("%i\n", Fibonacci[2]);
			Fibonacci[0] = Fibonacci[1];
			Fibonacci[1] = Fibonacci[2];
		}
	return 0;
}
