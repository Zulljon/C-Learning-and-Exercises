#include <stdio.h>

#define IN 1 /* внутри cлова */
#define OUT 0 /* вне cлова */

int asd1(){
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n' )
			++nl;
		if ((c == ' ') || (c == '\n') || (c == '\t')){
			state = OUT;
				}
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	printf ("%d %d %d\n", nl, nw, nc);
	}	
}

int asd2(){
	int c, nl, state;
	state = IN;
	nl = '\n';
	while ((c = getchar()) != EOF) {
		if ((c == ' ') /*|| (c == '\n')*/ || (c == '\t')){
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			putchar(nl);
			if ((c != ' ') /*|| (c != '\n')*/ || (c != '\t')){
				putchar(c);
			}
		}
		else {
		putchar(c);
		}
	}	
}

/* подcчет cтрок, cлов и cимволов */
int main (){
	asd2();
}
