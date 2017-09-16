#include <stdio.h>
#include <stdint.h>

int gcd (int u, int v){
	int temp;
	while ( v != 0 ) {
		temp = u % v;
		u = v;
		v = temp;
	}
	return u;
}

int lcm(int u, int v){
	int answer;

	if ( u>=0 && v>=0 )
		answer = u*v / gcd(u,v);
	else
		answer = -1;

	return answer;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	printf("least common multiple, input two number:");
	int u=10,v=15;
	scanf("%i %i",&u,&v );

	printf("lcm=%5i\n",lcm(u,v) );
	return 0;
}
