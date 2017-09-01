#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	float number1,number_acc;
	uint8_t command;

	printf("Simple calculator\nEnter your number and command:\n");

	while(1){
		scanf("%f %c",&number1, &command);
		// TODO check the number1 is correct integer
		switch(command){
			case '+':
				number1 = number1 + number_acc;
				printf(" = %.6f\n", number1 );
				break;
			case '-':
				number1 = number1 - number_acc;
				printf(" = %.6f\n", number1 );
				break;
			case '*':
				number1 = number1 * number_acc;
				printf(" = %.6f\n", number1 );
				break;
			case '/':
				if ( number1 != 0.0f ) {
					number1 = number1 / number_acc;
					printf(" = %.6f\n", number1 );
				}else{
					printf("ERROR: division by zero\n");
				}
				break;
			case 's':
				number_acc = number1;
				printf(" = %.6f\n", number_acc );
				break;
			case 'e':
				printf("Exit program. Bay.\n");
				return 0;
				break;

		}
	}

	return 0;
}
