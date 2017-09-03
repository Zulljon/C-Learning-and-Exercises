#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int ratingCounters[11], i, response;
	for ( i = 1; i <= 10; ++i )
		ratingCounters[i] = 0;

	printf ("Enter your responses\n");

	for ( i = 1; i <= 4294967296; ++i ) {
		scanf ("%i", &response);
		if (response == 999) {
			break;
		} else {
			if (response < 1 || response > 10)
				printf ("Bad response: %i\n", response);
			else
				++ratingCounters[response];
		}
	}
	printf ("\n\nRating Number of Responses\n");
	printf ("------ -------------------\n");

	for ( i = 1; i <= 10; ++i )
		printf ("%4i%14i\n", i, ratingCounters[i]);

	return 0;
}
