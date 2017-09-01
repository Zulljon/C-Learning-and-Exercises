#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int32_t number, right_digit;
	uint8_t flag = 0;
	printf ("Enter your number.\n");
	scanf ("%i", &number);

	if ( number < 0 ) {
		number = 0 - number ;
		flag = 1;
	}
	while ( number != 0 ) {
		right_digit = number % 10;
		if ( flag ) {
			printf("-");
			flag = 0;
		}
		printf ("%i", right_digit);
		number = number / 10;
	}

	printf ("\n");
	return 0;
}
