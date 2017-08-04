#include <stdio.h>
#include <stdlib.h>

//#define SSLASHH '\'

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int c=0, nl=0, nt=0, np=0, f=0;

	char st[] = "\\t";
	char sb[] = "\\b";
	char sslash[] = "\\";
	char kill = '\b';

int ptn(){
		while ((c = getchar()) != EOF){
	if 		(c == ' '){
		++np;}
	if ( c == '\t'){
		++nt;}
	if ( c == '\n'){
		++nl;}
	}
	printf ("%d %d %d\n", np, nt, nl);
}

int in_to_out_p(){
	char status=0;
	char kill = '\b';
	while ((f = getchar()) != EOF){
		if ( status == 0){
			if ( f == ' '){
			status=1;
			}
			putchar (f);
		}
		else if( status == 1){
			if ( f == ' '){
			status=0;
			}
			else {
				putchar (f);
				status=0;
			}
		}
		//putchar (f);
		}
}

int in_to_out_symbol(){

	while ((f = getchar()) != EOF){
		if ( f == '\t'){
			putchar (f);
			printf ("%s", st);
		}
		if( f == '\b'){
			printf ("%s", sb);
		}
		if( f == '\\' ){
			printf ("%s%s", sslash, sslash);
		}
			putchar (f);
		}
	}

int main(int argc, char *argv[]) {
	
	//ptn();
	//in_to_out_p();
	in_to_out_symbol();
//	printf ("%s a \n", st);
//	printf ("%s a \n", sb);
//	printf ("%s", sslash);
//	printf ("%s a \n", sslash);
}
