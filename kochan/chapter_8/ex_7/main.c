#include <stdio.h>
#include <stdint.h>

long int absa(long int x){
if ( x < 0l )
	x = -x;
return x;
}

long int power(int x,int y){
	long int n;
	long int result;
	x = absa(x);
	y = absa(y);
	result = (long int)x;
	for( n = 1 ; n < y ; ++n ){
		result *= (long int)x;
		//printf("%2li	%li\n",n,result);
	}
	return result;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	printf("%3li^%li = %li\n", 3l,4l,power(3l,4l) );
	printf("%3li^%li = %li\n", 2l,13l,(long int)power(2l,13l) );
	return 0;
}
