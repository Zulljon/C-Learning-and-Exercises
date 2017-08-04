#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <string.h>

#define rank	8

unsigned int func(unsigned int	M,unsigned int a, unsigned int c,unsigned int X0){
	unsigned int result[ M ];
	result[0] = X0;
	char i;
	printf("%i	%i	%i	%i \n", M, a,c,X0);
	
	for(i = 0 ; i < M - 1 ; i++){
		result[ i + 1 ] = fmod(( a * result[ i ] + c ) , M );
		printf("%i - %i \n", i, result[i]);
	}
	
}


int main(int argc, char *argv[]) {
	
	
	func(pow(2,rank),59,0,102);
	
	
	return 0;
}
