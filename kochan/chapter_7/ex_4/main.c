#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int32_t i , array_size = 10;
	float array[array_size] , average;
	// fill the array with some numbers
	printf("Enter the 10 float number\n");
	for ( i = 0; i < array_size; ++i ){
		scanf("%f", &array[i] );
	}
	// calculates the average of an array
	for ( i = 0; i < array_size; ++i ) {
			average += array[i];
	}
	average = average / 10;

	// print result
	printf ("Average of numbers in array\n");
	for ( i = 0; i < array_size; ++i )
		printf ("%9.3f\n", array[i]);
	printf(" = %f\n", average );

	return 0;
}
