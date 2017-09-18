// Program to sort an array of integers into ascending order
#include <stdio.h>
#include <stdint.h>

enum{
	ascending,
	descending
};

void sort (int a[], int n,int order){
	int i, j, temp;
	for ( i = 0; i < n - 1; ++i )
		for ( j = i + 1; j < n; ++j )
			if ( order==ascending ? (a[i] > a[j]) : (a[i] < a[j]) ) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int i;
	int array[16] = { 34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11 };

	printf ("The array before the sort:\n");

	for ( i = 0; i < 16; ++i )
		printf ("%i ", array[i]);

	sort (array, 16, descending);
	printf ("\n\nThe array after the descending sort:\n");
	for ( i = 0; i < 16; ++i )
		printf ("%i ", array[i]);

	sort (array, 16, ascending);
	printf ("\n\nThe array after the ascending sort:\n");
	for ( i = 0; i < 16; ++i )
		printf ("%i ", array[i]);

	printf ("\n");

	return 0;
}
