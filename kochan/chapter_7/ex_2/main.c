#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int32_t values[10];
	int32_t index;

	for (size_t i = 0; i < 10; i++) {
		values[i] = 0;
	}

	values[0] = 197;
	values[2] = -100;
	values[5] = 350;
	values[3] = values[0] + values[5];
	values[9] =
	values[5] / 10;
	--values[2];
	for ( index = 0; index < 10; ++index )
	printf ("values[%i] = %i\n", index, values[index]);
	return 0;
}
