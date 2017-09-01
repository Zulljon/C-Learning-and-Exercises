#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int32_t number, right_digit, reverse = 0;
	uint8_t flag = 0;
	printf ("Enter your number.\n");
	scanf ("%i", &number);

	// reverse number in variable
	if ( number < 0 ) {
		number = 0 - number ;
		flag = 1;
	}
	while ( number != 0 ) {
		reverse *= 10;
		reverse += number % 10;
		number = number / 10;
	}
	if ( flag ) {
		reverse = -reverse;
		flag = 0;
	}
	//printf("%i\n", reverse );

	// print number by words
	number = reverse;
	if ( number < 0 ) {
		number = 0 - number ;
		flag = 1;
	}
	while ( number != 0 ) {
		right_digit = number % 10;
		if ( flag ) {
			printf("- ");
			flag = 0;
		}
		//printf ("%i", right_digit);
		switch (right_digit) {
			case 1: printf("one ");break;
			case 2:	printf("two ");break;
			case 3:	printf("three ");break;
			case 4:	printf("four ");break;
			case 5:	printf("five ");break;
			case 6:	printf("six ");break;
			case 7:	printf("seven ");break;
			case 8:	printf("eight ");break;
			case 9:	printf("nine ");break;
			case 0:	printf("zero ");break;
		}
		number = number / 10;
	}

	printf ("\n");
	return 0;
}

/*
$ ./test
Enter your number.
-13
-31
- one three
*/
