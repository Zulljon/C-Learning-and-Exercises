
//E:\Micro_Cirquit\projects\avr
#include "E:\Micro_Cirquit\projects\avr\MY CAR (bt+avr+pc)\SHIP\defines.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>
#include "E:\Micro_Cirquit\projects\avr\MY CAR (bt+avr+pc)\SHIP\uart_functions.c"


struct {
	//фары передние 60 градусов с ШИМ
	unsigned char on_off:1;
	//яркость фар
	unsigned char brightness:4;
} headlights;// буфер для принятых переменных для фар

struct {
	//габариты задние красный/синий
	unsigned char back_red:1;
	unsigned char back_blue:1;
	//поворотники левые/правые соответственно
	unsigned char parking_lights_left:1;
	unsigned char parking_lights_right:1;
} LED;// буфер для принятых переменных для габаритов и поворотников

struct {
	unsigned char servoo	:1;
	unsigned char motorr	:1;
	unsigned char top_value:3;
	unsigned char prescaller:2;
	unsigned char leds	:1;
	unsigned char set_servo__left:1;
	unsigned char set_servo__rigft:1;
} init_variables_state;// установка флагов для начала расчета чего либо


volatile union {
	//байтовая переменная
	unsigned char word;
	
	//------сeрвопривод------//
	struct {
		unsigned char angle:5;
		//unsigned char turn_side:1;
		//unsigned char needs_turn:1;
		unsigned char assignation:3;
	} servo;
	
	//------двигатель------//
	struct {
		unsigned char speed			:4;
		unsigned char spin_rotation	:1;
		unsigned char assignation	:3;
	} motor;
	
	//------светодиоды------//
	//фары
	struct {
		unsigned char p_w_m:4;
		unsigned char on_off:1;
		unsigned char assignation:3;
	} front_leds;
	// задние огни, поворотники, подсветка снизу
	struct {
		unsigned char blue:1;
		unsigned char red:1;
		unsigned char parking_lights_right:1;
		unsigned char parking_lights_left:1;
		unsigned char neon_light:1;
		unsigned char assignation:3;
	} back_leds;
	
	//установка частоты шима двигателя
	struct {
		unsigned char top_value:3;
		unsigned char prescaller:2;
		unsigned char assignation:3;
		} motor_freq;
	
	// установка крайнего левого/правого положения серво
	struct {
		unsigned char values:5;
		unsigned char assignation:3;
		} set_servo__left;
	
	struct {
		unsigned char values:5;
		unsigned char assignation:3;
		} set_servo__right;
		
} inbound_processing ;


unsigned char pwm_speed, timer0_top_value;// переменная со скоростями двигателя (для ШИМа)
int servo_turn;
float leftmost,rightmost;
unsigned char a;
/*
#define N_OF_TIKS 7
char n=0;
char randoms[N_OF_TIKS];
*/
// таймер - 16-bit Timer/Counter1 with PWM
// делитель частоты 8
// Fast PWM Mode

unsigned int	timer1_top_value,
				servo_min_angle,
				servo_max_angle;
float			servo_temp;			

//-------------------------------------------------------//

void init_variables_main(void){
	init_variables_state.servoo = 1;
	init_variables_state.motorr = 1;
	init_variables_state.prescaller = 3;
	init_variables_state.leds = 0x0;
	init_variables_state.set_servo__left = 0x0;
	init_variables_state.set_servo__rigft = 0x0;
	leftmost = 0.001;
	rightmost = 0.002;
	//randoms[0] = 51;
	
	OCR1AH = (unsigned char)(3000>>8);
	OCR1AL = (unsigned char)3000;	
}

float set_servo_math(char a){
	float b;
	b = (float)((a/32)*0.0005);
	return b;
}

void init_variables(void){
	
	if (init_variables_state.servoo){
		timer1_top_value = (unsigned int)( F_CPU / (8 * 50 ) ) ; //8 делитель частоты F_CPU в таймере/клоке 16 битном, 50 требуема частота шима
		ICR1H = (unsigned char)(timer1_top_value>>8);
		ICR1L = (unsigned char)timer1_top_value;
		servo_min_angle = (unsigned int)( (timer1_top_value * leftmost) / 0.02) ; //leftmost >= 0.001
		servo_max_angle = (unsigned int)( (timer1_top_value * rightmost) / 0.02) ; //rightmost <= 0.002
		servo_temp  = (servo_max_angle - servo_min_angle) / (32);
		// временные переменные для серво привода 
		// в будущем перенести в EEPROM кроме коефициента servo_temp
		init_variables_state.servoo = 0x0;
		
		//USART_Transmit(	(unsigned char)(timer1_top_value>>8)	);
		//USART_Transmit(	(unsigned char)timer1_top_value	);
		//USART_Transmit(	ICR1H	);
		//USART_Transmit(	ICR1L	);
	}
	if (init_variables_state.motorr){
		timer0_top_value = (unsigned char)((0xFF)*(init_variables_state.top_value/8));
		OCR0B = timer0_top_value ;
		// пощитали и записали верхнее значение шима для моторчика в OCR0A
		switch(init_variables_state.prescaller){
			case 0 :	//8
				TCCR0B = (0<<CS02)|(1<<CS01)|(0<<CS00);
				break;
			case 1 :	//64
				TCCR0B = (0<<CS02)|(1<<CS01)|(1<<CS00);
				break;
			case 2 :	//256
				TCCR0B = (1<<CS02)|(0<<CS01)|(0<<CS00);
				break;
			case 3 :	//1024
				TCCR0B = (1<<CS02)|(0<<CS01)|(1<<CS00);
				break;
		}
		init_variables_state.motorr = 0x0 ;
	}

	if (init_variables_state.set_servo__left){
		leftmost = (float)(0.0015 - set_servo_math(inbound_processing.set_servo__left.values));
		init_variables_state.set_servo__left = 0x0;
	}
	if (init_variables_state.set_servo__rigft){
		rightmost = (float)(0.0015 + set_servo_math(inbound_processing.set_servo__right.values));
		init_variables_state.set_servo__rigft = 0x0;
	}

}

unsigned char PWM_speed_math(unsigned char pwm_speeeds){
	unsigned char pwm_a = (unsigned char)((timer0_top_value)*(pwm_speeeds/16));
	//USART_Transmit(pwm_a);
	return pwm_a;
}

unsigned int servo_angle(unsigned char r){
	int a = (unsigned int)(servo_min_angle + r * servo_temp);
	return a;
}

// функция обработки входных сообщений
unsigned char processing( unsigned char resive_word ){
	inbound_processing.word = resive_word;
	//PORTB=(1<<PORTB5);
	switch (inbound_processing.motor.assignation){
		case MOTORchik:
		if (inbound_processing.motor.speed == 0){
			TCCR0A |= (1<<COM0B1)|(1<<COM0B0);	// отключаю ногу OC0B
			// подаю комбинацию стопа на драйвер двигателя ВЫБРАТЬ КАКУЮ НИБУДЬ НОЖКУ!!!
			} 
		else {
			pwm_speed = PWM_speed_math(inbound_processing.motor.speed);			//	записать в ШИМ одну из ... скоростей!!!
			OCR0B = pwm_speed;
			if (inbound_processing.motor.spin_rotation){PORTB |= (1<<PORTB0);} else {PORTB &= ~(1<<PORTB0);} // поменять ногу в будущем!!!
			TCCR0A |= (1<<COM0B1)|(1<<COM0B0);	// включаю ногу OC0B
			}
		//USART_Transmit(timer0_top_value);
		
		break;
		
		case SERVO:
			//if (inbound_processing.servo.needs_turn){// возможна проблема с неправильной трактовкой, переставить хрень в if и else местами
			servo_turn = servo_angle(inbound_processing.servo.angle); 
			OCR1AH = (unsigned char)(servo_turn>>8);//8>>servo_turn //servo_turn>>8
			OCR1AL = (unsigned char)servo_turn;		// записываем в 16 битный ШИМ servo_turn  (длинну импульса в тактах)
				
			//USART_Transmit(servo_turn);		
			//}

		break;
		
		case LEDS_FRONT:
			headlights.on_off	=	inbound_processing.front_leds.on_off; // включаем фары
			headlights.brightness = inbound_processing.front_leds.p_w_m; 
			// установка яркости ФАР
			// настроить таймер2
			//и переcчитать туды inbound_processing.front_leds.p_w_m
			init_variables_state.leds = 0x1;
		break;
		case LEDS_B_PS:
			LED.back_blue	=	inbound_processing.back_leds.blue;
			LED.back_red	=	inbound_processing.back_leds.red;
			LED.parking_lights_left	=	inbound_processing.back_leds.parking_lights_left;
			LED.parking_lights_right	=	inbound_processing.back_leds.parking_lights_right;
			init_variables_state.leds = 0x1;
		break;
		
		case SET_MOTOR_FREQ:
			init_variables_state.prescaller = inbound_processing.motor_freq.prescaller ;
			init_variables_state.top_value = inbound_processing.motor_freq.top_value ;
			init_variables_state.motorr = 0x1;
		break;
		
		case SET_SERVO_RIGHT:
			init_variables_state.set_servo__rigft = 0x1;		
		break;
		case SET_SERVO_LEFT:
			init_variables_state.set_servo__left = 0x1;		
		break;	
	}
	return 0;
}

/*
unsigned char buffer_receive;

unsigned char buffer_receive[BUFFER_MAX];
unsigned char last_word_in_buffer = 0;

unsigned char buffer_RX( unsigned char a){
	if ( last_word_in_buffer < (BUFFER_MAX-1) ){
		++last_word_in_buffer;
	} else {	last_word_in_buffer = 0;	}
	buffer_receive[last_word_in_buffer] = a ;
	return buffer_receive[last_word_in_buffer];
}
*/

void LEDs_manipulations(void){
		
	if (init_variables_state.leds){
		
		if (LED.back_blue)		{	PORTB |= 1<<PORTB2 ;	}	else { PORTB &= ~(1<<PORTB2); }
		if (LED.back_red)		{	PORTB |= 1<<PORTB3 ;	}	else { PORTB &= ~(1<<PORTB3); }
		if (LED.parking_lights_left)	{	PORTB |= 1<<PORTB4 ;	}	else { PORTB &= ~(1<<PORTB4); }
		if (LED.parking_lights_right)		{	PORTB |= 1<<PORTB3 ; 	}	else { PORTB &= ~(1<<PORTB5); }
		//if (LED.back_right_red)		{	do_somethings(,,PORTB5);	}	else { PORTB &= ~(1<<PORTB5); }
		if (headlights.on_off == 1)	{
			// дернуть ногу 
			a = (unsigned char) ((headlights.brightness/16)*255);
			// записать а в таймер2 	
		}else{
			a = 12;//joke
		}
		
				
		init_variables_state.leds = 0x0;
	}
	
}
/*
unsigned int user_counter_1; 

struct {
	unsigned char compare_match_1:1;
	unsigned char compare_match_2:1;
	unsigned char compare_match_3:1;
} user_counter_flugs ;


unsigned int counter_on_TCNT1(){
	++user_counter_1;//увеличеваем переменную
	if (user_counter_1 = 255){	user_counter_1 = 0x0;	}//обнуляем переменную при достижении максимума
	return 0;
}

void contact_bounce( unsigned char PORTx, unsigned char port ){
	if ( user_counter_1 == randoms[n] ){
		PORTx ^=1<<port; //инверсия состояние "ножки"
	}
	++n;
	
}

unsigned int made_randoms_N(){
	char i;
	for (i=0;i<N_OF_TIKS;++i){
		randoms[i+1] = (unsigned char)fmod(((randoms[i]*27)+3),128);
	}
	return 0;
}
*/
/*
void init_pwm_2 (void){
	TCCR2A = (0<<COM2A1)|(0<<COM2A0)|(0<<COM2B1)|(0<<COM2B0)|(0<<WGM21)|(0<<WGM20);
	TCCR2B = (0<<FOC2A)|(0<<FOC2B)|(0<<WGM22)|(1<<CS22)|(1<<CS21)|(1<<CS20);
	TIMSK2 = (0<<OCIE2B)|(0<<OCIE2A)|(0<<TOIE2);
	TIFR2 = (0<<OCF2B)|(1<<OCF2A)|(1<<TOV2);
	ASSR = (1<<EXCLK)|(1<<AS2);|(0<<TCN2UB)|(0<<OCR2AUB)|(0<<OCR2BUB)|(0<<TCR2AUB)(0<<TCR2BUB);
	GTCCR = (0<<TSM)|(0<<PSRASY)|(0<<PSRSYNC);
	//OCR2A = 0;
	
}
*/

void init_pwm_1 (void){
	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(0<<COM1B1)|(0<<COM1B0)|(1<<WGM11)|(0<<WGM10);
	TCCR1B = (0<<ICNC1)|(0<<ICES1)|(1<<WGM13)|(1<<WGM12)|(0<<CS12)|(1<<CS11)|(0<<CS10);
	TCCR1C = (0<<FOC1A)|(0<<FOC1B);
	TIMSK1 = (0<<ICIE1)|(0<<OCIE1B)|(0<<OCIE1A)|(1<<TOIE1);
	TIFR1 = (0<<ICF1)|(0<<OCF1B)|(0<<OCF1A)|(0<<TOV1);
	//TCNT1H and TCNT1L and OCR1AH and OCR1AL and OCR1BH and OCR1BL and ICR1H and ICR1L
}

void init_pwm_0 (void){
	TCCR0A = (0<<COM0A1)|(0<<COM0A0)|(1<<COM0B1)|(1<<COM0B0)|(1<<WGM01)|(1<<WGM00);
	TCCR0B = (0<<FOC0A)|(0<<FOC0B)|(1<<WGM02)|(0<<CS02)|(1<<CS01)|(0<<CS00);
	TIMSK0 = (0<<OCIE0B)|(0<<OCIE0A)|(0<<TOIE0);
	//TIFR0 = (0<<OCF0B)|(0<<OCF0A)|(0<<TOV0);
	//TCNT0 OCR0A OCR0B
}

//инициализация апаратного USART
//настраивам регистры
void USART_Init(unsigned int UBRR)
{
	//Set baud rate
	UBRR0H = (unsigned char)(UBRR>>8);
	UBRR0L = (unsigned char)UBRR;
	UCSR0A = (0<<RXC0)|(0<<TXC0)|(1<<UDRE0)|(0<<FE0)|(0<<DOR0)|(0<<UPE0)|(0<<U2X0)|(0<<MPCM0);
	//Enable receiver and transmitter
	UCSR0B=(1<<RXCIE0)|(0<<TXCIE0)|(0<<UDRIE0)|(1<<RXEN0)|(1<<TXEN0)|(0<<UCSZ02)|(0<<RXB80)|(0<<TXB80);
	// Set frame format: 8data, 2stop bit
	UCSR0C=(0<<UMSEL01)|(0<<UMSEL00)|(0<<UPM01)|(0<<UPM00)|(0<<USBS0)|(1<<UCSZ01)|(1<<UCSZ00)|(0<<UCPOL0);
}

ISR(USART_RX_vect){
	//buffer_RX(UDR0);
	//processing(buffer_RX(UDR0));
	//buffer_receive = UDR0;
	//PORTB = UDR0 ;
	processing(UDR0);
}

ISR(TIMER1_OVF_vect){
	//counter_on_TCNT1();
	//contact_bounce(PORTB,PORTB5);
	//made_randoms_N();
}

void init_I_O (void){
	PORTB=(0<<PORTB0)|(0<<PORTB1)|(0<<PORTB2)|(0<<PORTB3)|(0<<PORTB4)|(0<<PORTB5);
	DDRB= (1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(1<<DDB4)|(1<<DDB5);
	/*
	PORTC=(0<<PORTC0)|(0<<PORTC0)|(0<<PORTC2)|(0<<PORTC3)|(0<<PORTC4)|(0<<PORTC5);
	DDRC= (0<<DDC0)|(0<<DDC0)|(0<<DDC2)|(0<<DDC3)|(0<<DDC4)|(0<<DDC5);
	
	PORTD=(0<<PORTD0)|(0<<PORTD0)|(0<<PORTD2)|(0<<PORTD3)|(0<<PORTD4)|(0<<PORTD5);
	DDRD= (0<<DDD0)|(0<<DDD0)|(0<<DDD2)|(0<<DDD3)|(0<<DDD4)|(0<<DDD5);
	*/
}

int main(void)
{
	
	init_I_O();
	//init_pwm_2();
	init_pwm_1();
	init_pwm_0();
	init_variables_main();
	USART_Init(MYUBRR);
	sei(); 
	
	
	while(1)
	{
		
		init_variables();
		LEDs_manipulations();
		//do_somethings();		
		
	}
}