// calculating the elapsed time
#include <stdio.h>
#include <stdint.h>

struct time_t{
	int hour;
	int minutes;
	int seconds;
};

uint32_t time_to_sec(struct time_t time ){
	return (time.hour*60*60+time.minutes*60+time.seconds);
}

struct time_t sec_to_time( uint32_t sec){
	struct time_t temp_time;

	temp_time.seconds = sec % 60;
	sec = (sec - temp_time.seconds)/60;
	temp_time.minutes = sec % 60;
	sec = (sec - temp_time.minutes)/60;
	temp_time.hour = sec % 24;

	return temp_time;
}

struct time_t elapsed_time(struct time_t a,struct time_t b){
	return (sec_to_time( time_to_sec(b) - time_to_sec(a) ));
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	//struct time_t time1 = {.hour=3,.minutes=45,.seconds=15};
	//struct time_t time2 = {.hour=9,.minutes=44,.seconds=3};
	struct time_t time1;
	struct time_t time2;
	struct time_t etime;

	printf("Enter begin time (hh:mm:ss)\n");
	scanf("%i:%i:%i", &time1.hour,&time1.minutes,&time1.seconds);
	printf("Enter end time (hh:mm:ss)\n");
	scanf("%i:%i:%i", &time2.hour,&time2.minutes,&time2.seconds);

	etime = elapsed_time(time1,time2);
	printf("Elapsed time is %d:%d:%d\n", etime.hour,etime.minutes,etime.seconds);

	return 0;
}
