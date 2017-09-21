#include <stdio.h>
#include <stdint.h>

#define ARRAY_SIZE 16

int32_t * init(){
	static int32_t array[ARRAY_SIZE]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	return array;
}

int32_t * inc(int32_t *a, int32_t size){
	int32_t * b = a;
	for (size_t i = 0; i < size; i++) {
		*a+=1;
		++a;
	}
	return b;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int32_t * p = inc(init(),ARRAY_SIZE);
	for (size_t i = 0; i < ARRAY_SIZE; i++) {
		printf("%2d\n", *p++ );
	}
	return 0;
}
