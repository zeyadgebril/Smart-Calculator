#ifndef INTERFACE_H_
#define INTERFACE_H_

#define DIO_u8_PORTA			0
#define DIO_u8_PORTB			1
#define DIO_u8_PORTC			2
#define DIO_u8_PORTD			3

#define DIO_u8_PIN0				0
#define DIO_u8_PIN1				1
#define DIO_u8_PIN2				2
#define DIO_u8_PIN3				3
#define DIO_u8_PIN4				4
#define DIO_u8_PIN5				5
#define DIO_u8_PIN6				6
#define DIO_u8_PIN7				7

#define DIO_u8_PIN_INPUT		0
#define DIO_u8_PIN_OUTPUT		1

#define DIO_u8_PIN_LOW			0
#define DIO_u8_PIN_HIGH			1

#define DIO_u8_PORT_INPUT		0
#define DIO_u8_PORT_OUTPUT      1




uint8_t DIO_u8SetPinDirection(uint8_t Copy_u8Port,uint8_t Copy_u8PinNumber,uint8_t Copy_u8Direction);

uint8_t DIO_u8SetPortDirection(uint8_t Copy_u8Port,uint8_t Copy_u8Direction);

uint8_t DIO_u8SetPinValue(uint8_t Copy_u8Port,uint8_t Copy_u8PinNumber,uint8_t Copy_u8Value);

uint8_t DIO_u8SetPortValue(uint8_t Copy_u8Port,uint8_t Copy_u8Value);

uint8_t DIO_u8GetPinValue(uint8_t Copy_u8Port,uint8_t Copy_u8PinNumber,uint8_t*Copy_u8Value);


#endif