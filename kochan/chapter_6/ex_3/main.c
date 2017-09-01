#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	uint32_t number1,number2;

	printf("Enter your #1 number: ");
	scanf("%i",&number1);

	printf("Enter your #2 number: ");
	scanf("%i",&number2);

	if ( number2 )
	{
		if ( number1>=number2 ){
			printf("%i / %i = %.3f\n",number1,number2, (float)((float)number1/(float)number2) );
		}else{
			printf("ERROR: #1 < #2\n");
		}
	} else {
		printf("ERROR: division by zero\n");
	}
		
	return 0;
}
