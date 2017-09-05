#include <stdio.h>
#include <stdint.h>

float absoluteValue (float x){
if ( x < 0 )
	x = -x;
return (x);
}
// Function to compute the square root of a number
double squareRoot (double x, float epsilon){
//const float epsilon = .00001;
double accuracy;
int32_t i=1;
double guess = 1.0;
printf("	iteration %ith; guess = %5.12f\tx-guess*guess = %5.12f\n", ++i , guess, (x-guess*guess) );
	while ( (absoluteValue ( (x/(guess * guess)) - 1) >= epsilon) &&
 			(absoluteValue (guess * guess - x) >= epsilon) ){
		guess = ( x / guess + guess ) / 2.0;
		printf("	iteration %ith; guess = %5.12f\tx-guess*guess = %5.12f\n", ++i , guess, (x-guess*guess) );
	}
		return guess;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){

printf ("squareRoot(2.0) = %5.12f\n", squareRoot (144.0 , 0.000000000001 ));
//printf ("squareRoot (2.0) = %f\n", squareRoot (2.0 , 0.1 ));
//printf ("squareRoot (2.0) = %f\n", squareRoot (2.0 , 1.0 ));
return 0;
}
