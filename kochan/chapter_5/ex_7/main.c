#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	int dollars, cents, count;
	for ( count = 1; count <= 10; ++count ) {
		printf ("Enter dollars: ");
		scanf ("%i", &dollars);
		printf ("Enter cents: ");
		scanf ("%i", &cents);
		printf ("$%i.%.2i\n\n", dollars, cents);
	}
	return 0;
}
/* output
Enter dollars: 13
Enter cents: 14
$13.14

Enter dollars: 23
Enter cents: 24
$23.24

Enter dollars: 5
Enter cents: 234
$5.234

Enter dollars: 234
Enter cents: 432
$234.432

Enter dollars: 234
Enter cents: 
432
$234.432

Enter dollars: 234
Enter cents: 234
$234.234

Enter dollars: 345
Enter cents: 4
$345.04

Enter dollars: 6
Enter cents: 68
$6.68

Enter dollars: 69
Enter cents: 78
$69.78

Enter dollars: 890
Enter cents: 234
$890.234
*/
