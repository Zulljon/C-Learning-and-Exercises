#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

void printf_bit(char a){
	volatile union asd {
		char byte;
		struct {
			unsigned char one:1;
			unsigned char two:1;
			unsigned char three:1;
			unsigned char four:1;
			unsigned char five:1;
			unsigned char six:1;
			unsigned char seven:1;
			unsigned char eight:1;
		}bits;
	} siti ;
	siti.byte = a;
	printf("%i%i%i%i%i%i%i%i\n",siti.bits.eight,siti.bits.seven,siti.bits.six,siti.bits.five,siti.bits.four,siti.bits.three,siti.bits.two,siti.bits.one);
//	char i;
//	char b = 128;
//	for(i=1;i<=8;i++){
//		if(a & b){
//			printf("1");
//		}else{
//			printf("0");
//		}
//		b >>= 1;
//	}
}

int print16(char N){
	char i;
	i = 1;
	int a = (1<<8);//65536
	while (i!=9) {
		if(N & a)	{printf("1");}			// битовое И - в данном случае вернет 2^i - если i-ый бит 1
	    else		{printf("0");}
			i++;
//	    if (a == 1){			// мы рассмотрели младший бит - выходим из цикла
//			break;}
	    a >>= 1;			// битовый сдвиг, запись числа смещается на один бит
		}					// аналогично делению на 2, но быстрее.
	putchar('\n');
}

char Zot(char a){
	volatile union {
		char byte;
		struct {
			unsigned char one:1;
			unsigned char two:1;
			unsigned char three:1;
			unsigned char four:1;
			unsigned char five:1;
			unsigned char six:1;
			unsigned char seven:1;
			unsigned char eight:1;
		}bits;
	} in,out ;
	in.byte = a;
	//printf("%d\n",in.byte);
	//out.byte = in.byte;
	out.bits.one=in.bits.eight;
	out.bits.two=in.bits.seven;
	out.bits.three=in.bits.six;
	out.bits.four=in.bits.five;
	out.bits.five=in.bits.four;
	out.bits.six=in.bits.three;
	out.bits.seven=in.bits.two;
	out.bits.eight=in.bits.one;
	//printf("%d\n",out.byte);
	return out.byte;
}

char Zot2(char a){
	volatile union {
		char byte;
		struct {
			unsigned char one:1;
			unsigned char two:1;
			unsigned char three:1;
			unsigned char four:1;
			unsigned char five:1;
			unsigned char six:1;
			unsigned char seven:1;
			unsigned char eight:1;
		}bits;
	} in ;
	in.byte = a;
	//printf("%d\n",in.byte);
	//out.byte = in.byte;
	char out;
	out=(in.bits.eight<<0)|(in.bits.seven<<1)|(in.bits.six<<2)|(in.bits.five<<3)|(in.bits.four<<4)|(in.bits.three<<5)|(in.bits.two<<6)|(in.bits.one<<7);
	//printf("%d\n",out.byte);
	return out;
}

char bitReverse(char a){
char _a = a;
_a = ((_a&0xCC)>>2)|((_a&0x33)<<2);
_a = ((_a&0xAA)>>1)|((_a&0x55)<<1);
_a = ((_a&0xF0)>>4)|((_a&0x0F)<<4);
return _a;
}

int main(int argc, char *argv[]) {
	//printf_bit(5);
	//printf("\n");
	//print16(5);
	//printf("\n%d\n%i\n",argv,argc);
	printf_bit(5);
	printf_bit(Zot(5));
	printf_bit(35);
	printf_bit(Zot(35));
	printf_bit(163);
	printf_bit(Zot(163));
	printf_bit(20);
	printf_bit(Zot2(20));
	printf_bit(34);
	printf_bit(bitReverse(34));
	return 0;
}
