#include <stdio.h>

#define	LOWER	0	 /* нижн€€ граница таблицы температур */
#define	UPPER	300	 /* верхн€€ граница */
#define	STEP	20	 /* шаг */	
	
	
	float fahr, celsius;
		
	char head_F[]={"Fahr"};
	char head_C[]={"Celsium"};
		
	float F_C(){
		fahr = LOWER;
		printf ("%5s %10s \n", head_F, head_C);
		while (fahr <= UPPER) {
			celsius = (5.0/9.0) * (fahr-32.0);
			printf ("%5.0f %10.1f\n", fahr, celsius);
			fahr = fahr + STEP;
		}
	//return;	
	}
	
	float F_C_2(){
		int fahhr;
		printf ("%5s %10s \n", head_F, head_C);
		for (fahhr = 300; fahhr >= 0; fahhr = fahhr - 20){
		printf ("%5d %10.1f\n", fahhr, (5.0/9.0)*(fahhr-32));
		}
	}
	
	float C_F(){
		celsius = LOWER;
		printf ("%5s %10s \n", head_C, head_F);
		while (celsius <= UPPER) {
			fahr = ((9.0/5.0) * celsius)+32;
			printf ("%5.0f %10.1f\n", celsius,fahr);
			celsius = celsius + STEP;
		}
	//return;
	}	
	
	int main(void)
	{
		
		F_C_2();
		C_F();
		
		return 0;	
	}
