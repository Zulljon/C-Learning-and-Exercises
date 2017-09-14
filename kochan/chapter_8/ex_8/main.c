#include <stdio.h>
#include <stdint.h>

#define epsilon (0.00001f)

float absoluteValue(float x){
if ( x < 0 )
	x = -x;
return (x);
}

// Function to compute the square root of a number
float squareRoot(float x){
//const float epsilon = .00001;
float accuracy;
int32_t i=1;
float guess = 1.0;
	while ( (absoluteValue ( (x/(guess * guess)) - 1) >= epsilon) &&
 			(absoluteValue (guess * guess - x) >= epsilon) ){
		guess = ( x / guess + guess ) / 2.0;
	}
		return guess;
}

int power(int x,int y){
	int n, result;
	x = absoluteValue(x);
	y = absoluteValue(y);
	result = x;
	for( n = 1 ; n < y ; ++n ){
		result *= (long int)x;
	}
	return result;
}

float determinant(uint32_t a, uint32_t b, uint32_t c){
	return (power(b,2) - 4*a*c);
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	float D,x1,x2,result;
	uint32_t a,b,c;
	printf("Enter a, b and c:" );

	scanf("%i %i %i", &a,&b,&c);
	//a=4,b=-17,c=-15;

	D = determinant(a,b,c);

	if ( D > epsilon ) {
		x1 = (-b + squareRoot(D))/(2*a);
		x2 = (-b - squareRoot(D))/(2*a);
		printf("root`s are:\nx1 = %.3f\nx2 = %.3f\n", x1, x2 );
	} else if ( D < epsilon ) {
		printf("Root`s is imaginary\n");
	}

	return 0;
}
