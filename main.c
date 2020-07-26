/*
 * Uso_timer1.c
 *
 * Created: 04/10/2018 08:18:57 a.m.
 * Author : Laptop
 */ //Aprendiendo a utilizar el TMR1 del ATMEGA328P	

#define F_CPU 2000000 //Crystal 16 Mhz, Div_by_8 -> 2Mhz
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
volatile uint8_t tmr1_overflow_count = 0;

ISR(TIMER1_OVF_vect){
	tmr1_overflow_count++;
	
	if(tmr1_overflow_count >= 61){ //Blinking led de 2 seg
		PORTD ^= 0xFF;
		tmr1_overflow_count = 0;
	}
}

void tmr1_config(){
	TCCR1B |= (1<<CS10)|(0<<CS11)|(0<<CS12); //Prescaler = 1;
	
	TIMSK1 |= (1<<TOIE1);
	
	//TIFR1 |= (X<<TOV1); ->Flag
	
	sei();
	
	TCNT1 = 0x0000;
}

void pin_config(){
	DDRD = (0xFF<<DDRD);
}

int main(void)
{
	pin_config();
    tmr1_config();
	
    while (1) 
    {
		
    }
}

