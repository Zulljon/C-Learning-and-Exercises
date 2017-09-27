#include <stdio.h>
#include <stdint.h>

typedef struct {
			int month;
			int day;
			int year;
		}date_t;

uint32_t N_calc(date_t T){
	return ((1461 * (T.month<=2 ? T.year-1 : T.year) ) / 4 + (153 * (T.month<=2 ? T.month+13 : T.month+1)) / 5 + T.day);
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	date_t date1={ .day=8,.month=8,.year=2004};
	date_t date2={.day=22,.month=2,.year=2005};
	uint32_t N1=N_calc(date1),N2=N_calc(date2);
	printf("%i - %i = %i\n", N2,N1,(N2-N1) );

	return 0;
}
