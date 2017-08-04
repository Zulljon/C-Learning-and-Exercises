#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int func(){
	int length, i;
    char c;
    i = length = 0;
    while ((c=getchar()) != EOF)
        if (c != ' ')
            ++length;
            else
            {
                if (c != '\n')
                {
                for (i=0; i < length; ++i)
                    printf("#");
                printf("\n");
                length = 0;
                }
                else
                {
                    for (i=0; i < length; ++i)
                        printf("#");
                }
            }
}

#define BUFFER_SIZE 255

	int n_s=BUFFER_SIZE;
	unsigned char buffer[BUFFER_SIZE];
	unsigned char ascii[BUFFER_SIZE];
	unsigned char symbol_freq[BUFFER_SIZE];
	unsigned char buffer2[] = { "Миша любит манку. Денис тоже.\n" };


int max_in_store(unsigned char store[] , int buf_s){
	unsigned char max = store[0];
	unsigned char i;
	for(i = 0; i < buf_s ; ++i){
		if(store[i] > max){
			max = store[i];
		}
	}
	return max;
}

int print_table(void){
		int ni;
		for(ni = 0 ; ni < BUFFER_SIZE; ++ni){
			printf(" %X	", ni);
			putchar(ascii[ni]);
			printf("	");
			printf("%i", symbol_freq[ni]);
			printf("\n");
		}
}

int print_digram(void){
	char symbol_1 = 0xB1;
	char symbol_0 = ' ';
	int ni,ny=0;
	int max_in_mass = max_in_store(symbol_freq,BUFFER_SIZE);
	char last_string[BUFFER_SIZE];

	for ( ni=0 ; ni<=BUFFER_SIZE ; ni++){
		last_string[ni] = symbol_freq[ni];
	}

	while ( max_in_mass > 0 ){
		for (ni=0; ni < BUFFER_SIZE ; ni++){
			if ( symbol_freq[ni] != 0 ){
				if( symbol_freq[ni] == max_in_mass ) {
					putchar(symbol_1);
					symbol_freq[ni]--;
				}
				else {
					putchar(symbol_0);
				}
			}
		}
		max_in_mass--;
		printf("\n");
	}

	//printf("\n");

	for (ni=0; ni < BUFFER_SIZE ; ni++){
		if ( last_string[ni] != 0){
			putchar(ascii[ni]);
		}
	}

}

int gistogram(void){

	int f,ni,ny;

	for(ni = 0 ; ni < BUFFER_SIZE; ++ni){
		buffer[ni] = ni;
		ascii[ni] = ni;
		symbol_freq[ni]	= 0;
	}

	//strcpy(buffer, buffer2);

	fgets(buffer, sizeof(buffer), stdin);

	ni=0;
	while ( buffer[ni] != '\n' ){
		ny=0;
		while ( buffer[ni] != ascii[ny] ){
			++ny;
			if ( buffer[ni] == ascii[ny] ){
			++symbol_freq[ny];
			}
			//++symbol_freq[0x2];		//отладочное
		}
		++ni;
		//++symbol_freq[5];		//отладочное
	}


}

int main(int argc, char *argv[]) {
	//printf("%s", buffer2);
	//func();
	gistogram();
	//print_table();
	print_digram();


	//printf("Max = %d \n", max_in_store(symbol_freq,BUFFER_SIZE));	//putchar(max_in_store(symbol_freq));
	return 0;
}
