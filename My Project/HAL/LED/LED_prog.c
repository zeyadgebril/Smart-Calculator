/*
 * LED_prog.c
 *
 * Created: 10/20/2023 3:35:31 AM
 *  Author: Zeyad
 */ 
#include "Configurations.h"

#include "LED_config.h"
#include "LED_interface.h"
#include "LED_privet.h"

void LED_u8Init(const LED_config_t *Copy_LED_obj)
{
	DIO_u8SetPinDirection(Copy_LED_obj->PORT,Copy_LED_obj->Pin_num,DIO_u8_PIN_OUTPUT);
}

uint8_t LED_u8TurnOn(const LED_config_t *Copy_LED_obj)
{
	uint8_t Local_u8ErrorState = OK;
	if (Copy_LED_obj-> ConnType==SRS_conn)   /*check for the connection type*/
	{
		DIO_u8SetPinValue(Copy_LED_obj->PORT,Copy_LED_obj->Pin_num,DIO_u8_PIN_HIGH);
	}
	else if (Copy_LED_obj->ConnType==SINK_conn) /*check for the connection type*/
	{
		DIO_u8SetPinValue(Copy_LED_obj->PORT,Copy_LED_obj->Pin_num,DIO_u8_PIN_LOW);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

uint8_t LED_u8TurnOff(const LED_config_t *Copy_LED_obj)
{
	uint8_t Local_u8ErrorState = OK;
	if (Copy_LED_obj-> ConnType==SRS_conn) /*check for the connection type*/
	{
		DIO_u8SetPinValue(Copy_LED_obj->PORT,Copy_LED_obj->Pin_num,DIO_u8_PIN_LOW);
	}
	else if (Copy_LED_obj->ConnType==SINK_conn) /*check for the connection type*/
	{
		DIO_u8SetPinValue(Copy_LED_obj->PORT,Copy_LED_obj->Pin_num,DIO_u8_PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}