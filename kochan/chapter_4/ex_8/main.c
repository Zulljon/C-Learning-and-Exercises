#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <float.h>

double roundOFF(double i, double j){
	double a,x,y,b;
	x = i;
	y = j;
	b = modf(x,&y);
	a = (i + j) - b ;
	return a;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	printf("round of 256 and 7 = %.5f\n", roundOFF(256.0f,7.0f) );
	printf("round of 365 and 7 = %.5f\n", roundOFF(365.0f,7.0f) );
	printf("round of 12.258,23 = %.5f\n", roundOFF(12.258,23.0f) );
	printf("round of 996 and 4 = %.5f\n", roundOFF(996.0f,4.0f) );

	double p = 7;
	printf("256mod7 = %.30f\n", modf(256,&p) );
	return 0;
}
