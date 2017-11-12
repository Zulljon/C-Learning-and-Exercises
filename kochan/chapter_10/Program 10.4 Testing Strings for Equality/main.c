// Function to determine if two strings are equal
#include <stdio.h>
#include <stdbool.h>

bool equalStrings (const char s1[], const char s2[]){
	int i = 0;
	bool areEqual;

	while ( s1[i] == s2 [i] && s1[i] != '\0' && s2[i] != '\0' )
		++i;

	if ( s1[i] == '\0' && s2[i] == '\0' )
		areEqual = true;
	else
		areEqual = false;

	return areEqual;
}

int main (void){
	bool equalStrings (const char s1[], const char s2[]);
	const char stra[] = "string compare test";
	const char strb[] = "string";

	printf ("1 %i\n", equalStrings (stra, strb));
	printf ("2 %i\n", equalStrings (stra, stra));
	printf ("3 %i\n", equalStrings (strb, "string"));
	return 0;
}
