
/*
 * PORT_reg.h
 *
 * Created: 10/28/2023 2:52:19 AM
 *  Author: Zeyad
 */ 

#ifndef PORT_REG_H_
#define PORT_REG_H_

#define DDRA 	*((volatile uint8_t*) 0x3A)
#define PORTA 	*((volatile uint8_t*) 0x3B)

#define DDRB 	*((volatile uint8_t*) 0x37)
#define PORTB 	*((volatile uint8_t*) 0x38)

#define DDRC	*((volatile uint8_t*) 0x34)
#define PORTC	*((volatile uint8_t*) 0x35)

#define DDRD 	*((volatile uint8_t*) 0x31)
#define PORTD	*((volatile uint8_t*) 0x32)


#endif

