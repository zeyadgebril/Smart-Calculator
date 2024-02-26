
/*
 * SEVENT_Segment_prog.c
 *
 * Created: 10/20/2023 9:07:59 PM
 *  Author: Zeyad
 */ 
#include "Configurations.h"
#include <util/delay.h>

#include "SEVENT_Segment_config.h"
#include "SEVENT_Segment_interface.h"
#include "SEVENT_Segment_privet.h"

#define dell 

uint8_t SEVEN_Segment_Display_u8SetNumber( SEVEN_Segment_config_t *Copy_obj,uint8_t Copy_u8Number)
{
		uint8_t Local_u8ErrorState = OK;
		uint8_t Local_u8OnesDigits;
		uint8_t Local_u8TenssDigits;
		uint8_t Local_u8Counter;

	 if( Copy_u8Number<=99 ) /* if the number is bigger then 10 and less than 100*/
		{
			for(Local_u8Counter=0 ; Local_u8Counter<=250;Local_u8Counter++)
			{
			/* Enable the first seven segment for few sec*/
			DIO_u8SetPinValue(Copy_obj->PORT_Enable,Copy_obj->EN2,DIO_u8_PIN_HIGH);
			
			/* get the ones number */
			Local_u8OnesDigits=Copy_u8Number%10;
			
			/*give the BCD pins its command*/
			DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinA,GET_BIT(Local_u8OnesDigits,0));
			DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinB,GET_BIT(Local_u8OnesDigits,1));
			DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinC,GET_BIT(Local_u8OnesDigits,2));
			DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinD,GET_BIT(Local_u8OnesDigits,3));
			_delay_ms(Enable_delay);
			
			/* Disable the first seven segment */
			DIO_u8SetPinValue(Copy_obj->PORT_Enable,Copy_obj->EN2,DIO_u8_PIN_LOW);
			
			/* Enable the second seven segment*/
			DIO_u8SetPinValue(Copy_obj->PORT_Enable,Copy_obj->EN1,DIO_u8_PIN_HIGH);
			
			/* get the tens number */
			Local_u8TenssDigits=(Copy_u8Number/10);
			
			/*give the BCD pins its command*/
			DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinA,GET_BIT(Local_u8TenssDigits,0));
			DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinB,GET_BIT(Local_u8TenssDigits,1));
			DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinC,GET_BIT(Local_u8TenssDigits,2));
			DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinD,GET_BIT(Local_u8TenssDigits,3));
			_delay_ms(Enable_delay);
			
			/* Disable the second seven segment */
			DIO_u8SetPinValue(Copy_obj->PORT_Enable,Copy_obj->EN1,DIO_u8_PIN_LOW);
			}
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
		return Local_u8ErrorState;
}

void SEVEN_Segment_Display_u8TurnOn(const SEVEN_Segment_config_t *Copy_obj)
{
	/* Setting the enable  of the seven segment display*/
	DIO_u8SetPinDirection(Copy_obj->PORT_Enable,Copy_obj->EN1,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(Copy_obj->PORT_Enable,Copy_obj->EN2,DIO_u8_PIN_OUTPUT);
	
	/*Setting the PINS of the seven segment display*/
	DIO_u8SetPinDirection(Copy_obj->PORT_Pin,Copy_obj->PinA,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(Copy_obj->PORT_Pin,Copy_obj->PinB,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(Copy_obj->PORT_Pin,Copy_obj->PinC,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(Copy_obj->PORT_Pin,Copy_obj->PinD,DIO_u8_PIN_OUTPUT);


}
void SEVEN_Segment_Display_u8TurnOff(const SEVEN_Segment_config_t *Copy_obj)
{
	DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinA,DIO_u8_PIN_LOW);
	DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinB,DIO_u8_PIN_LOW);
	DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinC,DIO_u8_PIN_LOW);
	DIO_u8SetPinValue(Copy_obj->PORT_Pin,Copy_obj->PinD,DIO_u8_PIN_LOW);
}