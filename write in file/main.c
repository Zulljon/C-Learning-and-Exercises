#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *myfile;

#define TOP_sa 13


float file_v1(){
	//int a=0;// читаем из файла хеш сумму
	int b=0;
	float z=0;// результат пересчeта хеш сумы в версию
	myfile = fopen("SHIP.c","rb");
		//fscanf(myfile,"%x \n", &a);
		fseek(myfile,1,SEEK_END);
		b = ftell(myfile)-1;
		z = log10f(powf(fmod((TOP_sa+b),b),sqrtf(cbrtf(b)))-0.9);
		//z = sqrtf(cbrtf(sqrtf(hypotf(expf(sqrtf(powf(fmod((TOP_sa-b),b),sqrtf(cbrtf(b))))),b))));
		//z = sqrtf(cbrtf(sqrtf(hypotf(expf(sqrtf(fmod((TOP_sa-b),b))),b))));
		//z = fmod((TOP_sa - b),b);
		//printf("%i\t%f\n",b,z);
				
	fclose(myfile);
	return z;
}

float file_v2(){
	myfile = fopen("SHIP.c","r");
	int c; // note: int, not char, required to handle EOF
	int n_line=1;
	int n_tabs=0,d=0,a=0,n=0;
	float m=0,j=0,b=0,x=0;
	
	while ((c = fgetc(myfile)) != EOF) { // standard C I/O file reading loop
		if(c == '\n')	++n_line;// считаем строки
		if(c == '\t')	++n_tabs;// считаем табы
		if(c == 'd')	++d;// считаем d
		if(c == 'a')	++a;// считаем a
		if(c == 'n')	++n;// считаем n
	}
	
	m = n+((d+a)+(n_line+n_tabs));
	j = n_line*n_tabs;
	b = sqrtf(((float)m)/(float)j);
	x = b*100;
	
	/*
	printf("n_line = %i\nn_tabs = %i\nd=%i\ta=%i\tn=%i\n",n_line,n_tabs,d,a,n);
	printf("m = %f\n",m);
	printf("j = %f\n",j);
	printf("b = %f\n",b);
	printf("x = %3.5f\n",x);
	*/
		
	fclose(myfile);
	return x;
}

float file_v3(){
	myfile = fopen("SHIP.c","r");
	int c; // note: int, not char, required to handle EOF
	int n_symbol=0;// количество символов
	int file_size=0;
	int n_space=0;
	int s=0;
	float b=0;
		
	while ((c = fgetc(myfile)) != EOF) { // standard C I/O file reading loop
		if	((c!='\n')&&(c!='\t')&&(c!='\b')&&(c!='\0')&&(c!='#'))	++n_symbol;// считаем символы без систeмемных
		if(c == '\b')	++n_space;// считаем space
	}
	
	fseek(myfile,1,SEEK_END);
	file_size = ftell(myfile)-1;
	s = file_size - n_symbol - n_space;
	b = ((float)s)/(float)file_size;
	
	/*
	printf("m = %i\n",m);
	printf("j = %i\n",j);*//*
	printf("file_size = %i\n",file_size);
	printf("n_symbol = %i\n",n_symbol);
	printf("s = file_size - n_symbol - n_space = %i + %i + %i = %i\n",file_size,n_symbol,n_space,s);
	printf("b = %f\n",b);
	*/
		
	fclose(myfile);
	return b;
}

int main(int argc, char *argv[]) {
	char buff_scan[10];
	//file_v1();
	//file_v2();
	//file_v3();
	FILE *myfile;
	myfile = fopen("out.txt","a+");
	if (myfile == 0) printf("file eq 0\n");
	
	//scanf(buff_scan);
	printf("%f\n%f\n%f\n",file_v1(),file_v2(),file_v3());
	//float b;
	//b = ((float)((file_v1()+file_v2())+file_v3()))/(float)3;
	//printf(myfile,"b = %f\n",file_v1());
	fprintf(myfile,"%.3f\n%.3f\n%.3f\n",file_v1(),file_v2(),file_v3()); //запись в файл
	//putc(file_v2(), myfile);
	//putc(file_v3(), myfile);
	/*
	float buffer[3]={file_v1(),file_v2(),file_v3()};
	double ret_code = fwrite(buffer, sizeof(float), sizeof(buffer), myfile);
	if (ret_code < (double)sizeof(buffer))
		if (ferror(myfile)){
			perror("fwrite()");
			fprintf(stderr,"fwrite() failed in file %s at line # %d\n", __FILE__,__LINE__-5);
			exit(EXIT_FAILURE);
		}
		*/
	/*	
	char c;
	int ret_code = 0;
    for (c = 'a'; (ret_code != EOF) && (c != 'z'); c++)
		ret_code = fputc(c, myfile);
		*/
	fclose(myfile);
	
return 0;
}
