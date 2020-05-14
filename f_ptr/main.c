// Program to generate the first 15 Fibonacci numbers witout array
#include <stdio.h>
#include <stdint.h>
#include "main.h"

struct zulljon {
	int32_t (* print)(const char * restrict,  ...);
	uint32_t (* calc)();
} test;

uint32_t add (uint32_t a , uint32_t b ){
	return (a + b);
}

uint32_t main(uint32_t argc, uint8_t *argv[]){

	test.print = &printf ;
	test.calc = &add ;

	printf("Begin Program.\n");
	test.print("add = %d\n", test.calc(1,2) );

	return 0;
}
