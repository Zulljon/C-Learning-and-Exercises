#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	uint32_t number1,number2;

	printf("Enter your #1 number: ");
	scanf("%i",&number1);

	printf("Enter your #2 number: ");
	scanf("%i",&number2);

	if ( number1%number2 )
	{
		printf("#1 not divisible by #2\n");
	} else {
		printf("#1 are divisible by #2\n");
		}
	

	return 0;
}
