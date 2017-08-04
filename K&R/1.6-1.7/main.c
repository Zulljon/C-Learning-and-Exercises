#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* копирование ввода на вывод; 2-я версия */

int main(/*int argc, char *argv[]*/) {
	int b,g;
	while ((b = getchar()) != EOF){
		putchar (b);
		
		if (getchar() != EOF){
		g = 1;	}
		else if (getchar() == EOF) {
		g = 0;
		}
		printf(" %i \n", g );
	}
	printf(" %i \n", EOF);
	
//	return 0;
}
