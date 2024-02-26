
/*
 * PORT_prog.c
 *
 * Created: 10/28/2023 2:52:07 AM
 *  Author: Zeyad
 */ 


#include "Configurations.h"

#include "PORT_config.h"
#include "PORT_privet.h"
#include "PORT_interface.h"
#include "PORT_reg.h"


void PORT_voidInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	
	PORTA = PORTA_INITAL_VALUE;
	PORTB = PORTB_INITAL_VALUE;
	PORTC = PORTC_INITAL_VALUE;
	PORTD = PORTD_INITAL_VALUE;

}

