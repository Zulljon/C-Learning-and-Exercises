#include <stdio.h>
#include <stdint.h>

int32_t check_for_prime(int32_t var){
	int32_t p, d;
	_Bool isPrime;

	if (var == 2 || var == 3)
		return 1;

	for ( p = 5; 1 ; p+=2 ) {
		isPrime = 1;
		for ( d = 3; d < p; d+=2 ){
			if ( p % d == 0 )
				isPrime = 0;
		}
		if ( isPrime != 0 && p == var ){
			return 1;
		}else if ( p>var ) {
			return 0;
		}
	}
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int32_t var;

	printf("enter you number:");
	scanf("%i",&var );

	if ( check_for_prime(var) == 1 )
		printf ("number %i is prime\n", var);
	else
		printf ("number %i is not prime\n", var);

	return 0;
}
