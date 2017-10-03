#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

struct time_t{
	int hour;
	int minutes;
	int seconds;
};

struct date_t {
	int month;
	int day;
	int year;
};

struct dateAndTime {
	struct date_t sdate;
	struct time_t stime;
};

// Function to update the time by one second
struct time_t timeUpdate (struct time_t now){
	++now.seconds;
	if ( now.seconds == 60 ){	// next minute
		now.seconds = 0;
		++now.minutes;

		if ( now.minutes == 60 ) {	// next hour
			now.minutes = 0;
			++now.hour;
			if ( now.hour == 24 ) // midnight
				now.hour = 0;
		}
	}
	return now;
}

// Function to determine if it's a leap year
bool isLeapYear (struct date_t d){
	bool leapYearFlag;
	if ( (d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0 )
		leapYearFlag = true;// It's a leap year
	else
		leapYearFlag = false; // Not a leap year
	return leapYearFlag;
}

// Function to find the number of days in a month
int numberOfDays (struct date_t d){

	int days;
	bool isLeapYear (struct date_t d);
	const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ( isLeapYear && d.month == 2 )
		days = 29;
	else
		days = daysPerMonth[d.month - 1];

	return days;
}

struct date_t dateUpdate (struct date_t today){
	struct date_t tomorrow;
	int numberOfDays (struct date_t d);
	if ( today.day != numberOfDays (today) ) {
		tomorrow.day = today.day + 1;
		tomorrow.month = today.month;
		tomorrow.year = today.year;
	}
	else if ( today.month == 12 ) {
		// end of year
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	}
	else {
		// end of month
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}
	return tomorrow;
}

struct dateAndTime clockKeeper(struct dateAndTime D_A_T){
	D_A_T.stime = timeUpdate(D_A_T.stime);
	if ( D_A_T.stime.hour == 0 && D_A_T.stime.minutes == 0 ) {
		D_A_T.sdate = dateUpdate(D_A_T.sdate);
	}
	return D_A_T;
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	struct dateAndTime dateAndTime = {\
		{.day=31 ,.month=12 ,.year=2038}, \
		{.hour=23,.minutes=59,.seconds=59}	};

	printf("Today date and time:\n%2i.%2i.%4i %2i:%2i:%2i\n",\
	dateAndTime.sdate.day,\
 	dateAndTime.sdate.month,\
	dateAndTime.sdate.year,\
	dateAndTime.stime.hour,\
 	dateAndTime.stime.minutes,\
	dateAndTime.stime.seconds );

	dateAndTime = clockKeeper(dateAndTime);

	printf("Tomorrow date and time:\n%2i.%2i.%4i %2i:%2i:%2i\n",\
	dateAndTime.sdate.day,\
 	dateAndTime.sdate.month,\
	dateAndTime.sdate.year,\
	dateAndTime.stime.hour,\
 	dateAndTime.stime.minutes,\
	dateAndTime.stime.seconds );
	return 0;
}
