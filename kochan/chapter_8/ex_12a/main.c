#include <stdio.h>
#include <stdint.h>

int32_t array1[4][5],array2[5][4],z=0;

void transposeMatrix(){
	//int32_t src[4][5],int32_t dest[5][4]
	for (size_t a = 0; a < 4; a++) {
		for (size_t b = 0; b < 5; b++) {
			array2[b][a]=array1[a][b];
		}
	}
	//return dest;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int32_t z=0;

	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 5; j++) {
			array1[i][j] = z;
			++z;
			printf("%5i", array1[i][j] );
		}
		printf("\n");
	}
printf("\n");
z=0;
	for (size_t i = 0; i < 5; i++) {
		for (size_t j = 0; j < 4; j++) {
			array2[i][j] = 357;
			printf("%5i", array2[i][j] );
		}
		printf("\n");
	}
printf("\n");

transposeMatrix();

	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 5; j++) {
			printf("%5i", array1[i][j] );
		}
		printf("\n");
	}
printf("\n");
	for (size_t i = 0; i < 5; i++) {
		for (size_t j = 0; j < 4; j++) {
			printf("%5i", array2[i][j] );
		}
		printf("\n");
	}
printf("\n");

	return 0;
}
