#include <stdio.h>
#include <stdint.h>

uint32_t main(uint32_t argc, uint8_t *argv[]){
	/*
	Which of the following are invalid constants? Why?
	123.456
	0001
	0Xab05
	123.5e2
	98.6F
	0996	// octal integer not include symbol 9 and higher
	1234uL
	1.234L
	0XABCDEFL
	0x10.5	// cant consist "." , maybe it needs an exponent
	0xFFFF
	0L
	.0001
	98.7U
	-12E-12
	1.2Fe-7
	197u
	0xabcu
	0X0G1	// error: invalid suffix "G1" on integer constant
	123L
	-597.25
	+12
	17777s	// error: invalid suffix "s" on integer constant
	07777
	15,000	// "." not ","
	100U
	+123
	*/
	uint32_t var = 17777s;
printf("%i\n", var );
	return 0;
}
