#include <stdio.h>
#include <stdint.h>

int32_t arraySum(uint32_t array[], uint32_t size){
	int32_t Sum;
	for (size_t i = 0; i < size; i++) {
		Sum += array[i];
	}
	return Sum;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int32_t size = 100;
	int32_t ara[size];

	for (size_t i = 0; i < size; i++)
		ara[i] = i;

	printf("sum of elements in array = %i\n", arraySum(ara,size) );
	return 0;
}
