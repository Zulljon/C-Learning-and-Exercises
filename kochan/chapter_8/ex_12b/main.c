#include <stdio.h>
#include <stdint.h>

void displayMatrix (int32_t nRows, int32_t nCols, int32_t matrix[nRows][nCols]){
	int32_t row, column;
	for ( row = 0; row < nRows; ++row) {
		for ( column = 0; column < nCols; ++column )
			printf ("%5i", matrix[row][column]);
		printf ("\n");
	}
}

void transposeMatrix (int32_t nRows,int32_t nCols,int32_t src[nRows][nCols],int32_t dest[nCols][nRows]){
	for (size_t a = 0; a < nRows; a++) {
		for (size_t b = 0; b < nCols; b++) {
			dest[b][a]=src[a][b];
		}
	}
	// print array`s to console
		displayMatrix(nRows,nCols,src);
		printf("\n");
		displayMatrix(nCols,nRows,dest);
		printf("\n");
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	uint32_t x=15,y=25;
	int32_t array1[x][y],array2[y][x],z=0;
// fill the array`s with something different
	for (size_t i = 0; i < x; i++) {
		for (size_t j = 0; j < y; j++) {
			array1[i][j] = z;
			++z;
		}
	}
	printf("\n");
	z=0;
	for (size_t i = 0; i < y; i++) {
		for (size_t j = 0; j < x; j++) {
			array2[i][j] = 13;
		}
	}
	printf("\n");

// print array`s to console, one more time
	displayMatrix(x,y,array1);
	printf("\n");
	displayMatrix(y,x,array2);
	printf("\n");

// transpose Matrix array1 to array2
	transposeMatrix(x,y,array1,array2);

	return 0;
}
