#include <stdio.h>
#include <stdint.h>

float F_to_C(float F){
	return (F - 32.0f) / 1.8f;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	printf("27 degrees Fahrenheit equal %.2f degrees of Celsius\n", F_to_C(27) );
	return 0;
}
