//program that displays the day of the week on which a particular date falls
#include <stdio.h>
#include <stdint.h>

typedef struct {
			int month;
			int day;
			int year;
		}date_t;

struct day_name_t{
	char name[10];
};

const struct day_name_t day[7] =
	{	{"sunday"},
		{"monday"},
		{"tuesday"},
		{"wednesday"},
		{"thursday"},
		{"friday"},
		{"saturday"}
	};

uint32_t calc_date_number(date_t T){
	return ((1461 * (T.month<=2 ? T.year-1 : T.year) ) / 4 + (153 * (T.month<=2 ? T.month+13 : T.month+1)) / 5 + T.day);
}

uint32_t get_day_of_week(date_t date){
	return (calc_date_number(date) - 621049) % 7;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	date_t date1;

	printf("Enter date(dd mm yy) ");
	scanf("%i %i %i", &date1.day,&date1.month,&date1.year );
	printf("It was %s.\n",day[get_day_of_week(date1)].name);

	return 0;
}
