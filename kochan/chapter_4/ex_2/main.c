#include <stdio.h>
#include <stdint.h>

//Which of the following are invalid variable names? Why?

uint32_t main(uint32_t argc, uint8_t *argv[]){
/*
Int
Calloc
floating
ReInitialize
char // this is invalid
Xx
_1312
_
6_05
alpha_beta_routine
z
A$
*/
uint32_t char = 13;
uint32_t var = char;
printf("%i\n", var );
	return 0;
}
