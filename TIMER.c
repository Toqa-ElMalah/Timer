/*
 * TIMER.c
 *
 * Created: 10/26/2023 12:00:49 AM
 *  Author: DELL
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>
#include "std_macrous.h"

void Timer_CTC_init_interrupt (void){
	SET_BIT(TCCR0,WGM01);
	OCR0 = 80;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	sei();
	SET_BIT(TIMSK,OCIE0);
}

void Timerwave_NonPWM (void){
	
	SET_BIT(DDRB,3); //OC0 as output
	SET_BIT(TCCR0,WGM01); //CTC mode
	OCR0=64;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00); //TOGGLE OC0
}