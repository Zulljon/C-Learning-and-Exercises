#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	uint32_t number, right_digit, sum = 0;
	printf ("Enter your number.\n");
	scanf ("%i", &number);
	
	while ( number != 0 ) {
		right_digit = number % 10;
		printf ("%i", right_digit);
		number = number / 10;
		if ( number != 0 )
		{
			printf (" + ");
		} else {
			printf(" = ");
		}
		sum += right_digit;
	}
	
	printf ("%i\n",sum);
	return 0;
}
