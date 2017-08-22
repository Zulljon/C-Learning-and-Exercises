#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	uint8_t c, d;
	c = 'd';
	d = c;
	printf ("d = %c\n", d);
	return 0;
}

//answer `d = d`
