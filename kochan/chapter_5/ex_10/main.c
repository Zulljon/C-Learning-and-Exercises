#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	uint32_t number, right_digit;
	printf ("Enter your number.\n");
	scanf ("%i", &number);
	
	while ( number != 0 ) {
		right_digit = number % 10;
		printf ("%i", right_digit);
		number = number / 10;
	}
	
	printf ("\n");
	return 0;
}


/*
OUTPUT:

$ C Learning and C Exercises/kochan/chapter_5/ex_10 $ ./test
Enter your number.
-13
3827694924

$ C Learning and C Exercises/kochan/chapter_5/ex_10 $ ./test
Enter your number.
-666
0366694924

$ C Learning and C Exercises/kochan/chapter_5/ex_10 $ ./test
Enter your number.
-1
5927694924

$ C Learning and C Exercises/kochan/chapter_5/ex_10 $ ./test
Enter your number.
-2
4927694924

*/