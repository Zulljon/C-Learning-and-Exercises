#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){

	uint32_t n = 150,i,j;
	uint32_t array[n];
	array[0]=0;
	array[1]=1;

	for (i = 2; i < n; i++)
		array[i] = 0;

	for ( i = 2 ; i < n ; ++i ) {
		if ( array[i] == 0 ) {
			for ( j = i; i*j < n; ++j ) {
				array[i*j] = 1;
			}
		}
	}

	for ( i = 2 , j=1; i < n; i++) {
		if ( array[i] == 0 ) {
			printf("j = %3i =>  i = %3i\n",j++, i);
		}
	}

	return 0;
}
