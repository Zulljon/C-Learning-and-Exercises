#include <stdio.h>
#include <stdint.h>

typedef struct {
			int month;
			int day;
			int year;
		}date_t;

uint32_t calc_date_number(date_t T){
	uint32_t N;
	N = ((1461 * (T.month<=2 ? T.year-1 : T.year) ) / 4 + (153 * (T.month<=2 ? T.month+13 : T.month+1)) / 5 + T.day);
	return N;
}

uint32_t fix_N(uint32_t N){
	date_t n28_febr_1900={.day=28,.month=2,.year=1900};
	date_t n1_march_1800={.day=1,.month=3,.year=1800};
	date_t n1_march_1700={.day=1,.month=3,.year=1700};
	uint32_t N_28_febr_1900 = calc_date_number(n28_febr_1900);
	uint32_t N_1_march_1800 = calc_date_number(n1_march_1800);
	uint32_t N_1_march_1700 = calc_date_number(n1_march_1700);
	if ( N > N_1_march_1800 && N <= N_28_febr_1900 ) {
		N = N+1;
	}
	if ( N >= N_1_march_1700 && N < N_1_march_1800 ) {
		N = N+2;
	}
	return N;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	date_t date1;
	date_t date2;

	date1.day=8,date1.month=8,date1.year=2004;
	date2.day=22,date2.month=2,date2.year=2005;

	printf("Enter first date (dd mm yyyy):");
	//date1.day=8,date1.month=8,date1.year=2004;
	scanf("%i %i %i", &date1.day,&date1.month,&date1.year );
	printf("Enter second date (dd mm yyyy):");
	//date2.day=22,date2.month=2,date2.year=2005;
	scanf("%i %i %i", &date2.day,&date2.month,&date2.year );

	uint32_t N1=fix_N(calc_date_number(date1)),N2=calc_date_number(date2);
	printf("%i - %i = %i\n", N2,N1,(N2-N1) );

	return 0;
}
