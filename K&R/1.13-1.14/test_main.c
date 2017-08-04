#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define BUFFER_SIZE 255

unsigned char max_in_store(unsigned char store[]){
	unsigned char max = store[0];
	unsigned char i, temp;
	for(i = 1; i < BUFFER_SIZE ; ++i){
            temp = store[i];
	    if(temp > max) max = temp;
            printf("%i\n", max);
	}
	return max;
}

int main(int argc, char *argv[]) {

	char arr[BUFFER_SIZE] = {0, 2, 3, 5, 10, 15, 1};
	
	printf("Max  =%d  \n", max_in_store(arr));	//putchar(max_in_store(symbol_freq));
	return 0;
}
