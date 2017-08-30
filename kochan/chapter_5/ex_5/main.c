#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){

	int n,two_to_the_n = 1;
	printf("TABLE OF POWERS OF TWO\n\n");
	printf(" n	2 to the n\n");
	printf("--- ---------------\n");
	
	for( n = 0 ; n <= 10 ; ++n ){
		printf("%2i	%i\n",n,two_to_the_n);
		two_to_the_n *= 2;
	}

	return 0;
}
