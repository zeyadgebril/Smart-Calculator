/*
 * DIO_prog.c
 *
 * Created: 10/16/2023 10:16:44 PM
 *  Author: Zeyad
 */ 
#include "Configurations.h"

#include "DIO_interface.h"
#include "DIO_privet.h"
#include "DIO_reg.h"
#include "DIO_config.h"

  
  uint8_t DIO_u8SetPinDirection(uint8_t Copy_u8Port,uint8_t Copy_u8PinNumber,uint8_t Copy_u8Direction)
  {
	  uint8_t Local_u8ErrorState = OK;
	  
	  if(Copy_u8PinNumber<=DIO_u8_PIN7)
	  {
		  if(Copy_u8Direction==DIO_u8_PIN_INPUT)
		  {
			  switch(Copy_u8Port)
			  {
				  case DIO_u8_PORTA: CLR_BIT(DDRA,Copy_u8PinNumber);break;		/*SET the pin input*/
				  case DIO_u8_PORTB: CLR_BIT(DDRB,Copy_u8PinNumber);break;
				  case DIO_u8_PORTC: CLR_BIT(DDRC,Copy_u8PinNumber);break;
				  case DIO_u8_PORTD: CLR_BIT(DDRD,Copy_u8PinNumber);break;
				  default:Local_u8ErrorState=NOK; break; /*Error if the given port is not founded*/
			  }
		  }
		  else if (Copy_u8Direction=DIO_u8_PIN_OUTPUT)
		  {
			  switch(Copy_u8Port)
			  {
				  case DIO_u8_PORTA: SET_BIT(DDRA,Copy_u8PinNumber);break;			/*SET the pin output*/
				  case DIO_u8_PORTB: SET_BIT(DDRB,Copy_u8PinNumber);break;
				  case DIO_u8_PORTC: SET_BIT(DDRC,Copy_u8PinNumber);break;
				  case DIO_u8_PORTD: SET_BIT(DDRD,Copy_u8PinNumber);break;
				  default:Local_u8ErrorState=NOK;break;  /*Error if the given port is not founded*/
			  }
		  }
		  
		  else
		  {
			  /* Error Direction Input*/
			  Local_u8ErrorState = NOK;
		  }
	  }
	  else
	  {
		  /*Error Pin Number Input */
		  Local_u8ErrorState=NOK;
	  }
	  
	  
	  return Local_u8ErrorState;
  }
  
  uint8_t DIO_u8SetPortDirection(uint8_t Copy_u8Port,uint8_t Copy_u8Direction)
  {
	  uint8_t Local_u8ErrorState = OK;
	  switch(Copy_u8Port)
	  {
		  case DIO_u8_PORTA: DDRA=Copy_u8Direction;break;
		  case DIO_u8_PORTB: DDRB=Copy_u8Direction;break;
		  case DIO_u8_PORTC: DDRC=Copy_u8Direction;break;
		  case DIO_u8_PORTD: DDRD=Copy_u8Direction;break;
		  default:Local_u8ErrorState=NOK;break;
	  }
	  
	  return Local_u8ErrorState;
  }
 

/* IF U DON'T USE THE PORT FILE JUST UNCOMMENT THE SET_PIN_VALUE & SET_PORT_VALUE*/

uint8_t DIO_u8SetPinValue(uint8_t Copy_u8Port,uint8_t Copy_u8PinNumber,uint8_t Copy_u8Value)

{
	uint8_t Local_u8ErrorState = OK;
	if(Copy_u8PinNumber<=DIO_u8_PIN7){
		if (Copy_u8Value==DIO_u8_PIN_LOW)
		{
			switch(Copy_u8Port)
			{
				case DIO_u8_PORTA: CLR_BIT(PORTA,Copy_u8PinNumber);break;
				case DIO_u8_PORTB: CLR_BIT(PORTB,Copy_u8PinNumber);break;
				case DIO_u8_PORTC: CLR_BIT(PORTC,Copy_u8PinNumber);break;
				case DIO_u8_PORTD: CLR_BIT(PORTD,Copy_u8PinNumber);break;
				default:Local_u8ErrorState=NOK; break;  /*Error if the given port is not founded*/
			}
		}
		else if(Copy_u8Value==DIO_u8_PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
				case DIO_u8_PORTA: SET_BIT(PORTA,Copy_u8PinNumber);break;
				case DIO_u8_PORTB: SET_BIT(PORTB,Copy_u8PinNumber);break;
				case DIO_u8_PORTC: SET_BIT(PORTC,Copy_u8PinNumber);break;
				case DIO_u8_PORTD: SET_BIT(PORTD,Copy_u8PinNumber);break;
				default:Local_u8ErrorState=NOK;break; /*Error if the given port is not founded*/
			}
		}
		else
		{
			/* Error Direction Input*/
			Local_u8ErrorState =NOK;
		}
	}
	else
	{
		/*Error Pin Number Input */
		Local_u8ErrorState =NOK;
	}
	return Local_u8ErrorState;
}

uint8_t DIO_u8SetPortValue(uint8_t Copy_u8Port,uint8_t Copy_u8Value)
{
	uint8_t Local_u8ErrorState = OK;
	switch(Copy_u8Port)
	{
		case DIO_u8_PORTA: PORTA=Copy_u8Value;break;
		case DIO_u8_PORTB: PORTB=Copy_u8Value;break;
		case DIO_u8_PORTC: PORTC=Copy_u8Value;break;
		case DIO_u8_PORTD: PORTD=Copy_u8Value;break;
		default:Local_u8ErrorState=NOK;
	}
	
	return Local_u8ErrorState;
}

uint8_t DIO_u8GetPinValue(uint8_t Copy_u8Port,uint8_t Copy_u8PinNumber,uint8_t* Copy_pu8Value)
{
	uint8_t Local_u8ErrorState =OK;
	if(Copy_u8PinNumber<=DIO_u8_PIN7)
	{
		switch(Copy_u8Port)
		{
			case DIO_u8_PORTA:*Copy_pu8Value=GET_BIT(PINA,Copy_u8PinNumber) ;break;     /*Get the value og the pin*/
			case DIO_u8_PORTB:*Copy_pu8Value=GET_BIT(PINB,Copy_u8PinNumber) ;break;
			case DIO_u8_PORTC:*Copy_pu8Value=GET_BIT(PINC,Copy_u8PinNumber) ;break;
			case DIO_u8_PORTD:*Copy_pu8Value=GET_BIT(PIND,Copy_u8PinNumber) ;break;
			default:Local_u8ErrorState=NOK;break; /*Error if the given port is not founded*/
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
	
}