/*
 * studoi5.c
 *
 * Created: 21.11.2015 15:05:45
 *  Author: DAN
 */ 

#include <avr/io.h>

char Zotr(char a){
	char b = a;
	b = ((b & 0xCC)>>2)|((b & 0x33)<<2);
	b = ((b & 0xAA)>>1)|((b & 0x55)<<1);
	b = ((b & 0xF0)>>4)|((b & 0x0F)<<4);
	return b;
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

	char out;
	out=(in.bits.eight<<0)|(in.bits.seven<<1)|(in.bits.six<<2)|(in.bits.five<<3)|(in.bits.four<<4)|(in.bits.three<<5)|(in.bits.two<<6)|(in.bits.one<<7);

	return out;
}

int main(void){
	char d,n,xc,i;
	xc = Zotr(7);
	d = Zot(5);
	n = Zot2(3);
	while(1)
    {
		d = Zot(5);
		n = Zot2(3);
		xc = Zotr(7);
		i = d + n + xc;
    }
}