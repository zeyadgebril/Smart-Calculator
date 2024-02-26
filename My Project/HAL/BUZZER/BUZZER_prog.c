/*
 * BUZZER_prog.c
 *
 * Created: 10/20/2023 4:39:08 AM
 *  Author: Zeyad
 */ 
#include "Configurations.h"

#include "BUZZER_config.h"
#include "BUZZER_interface.h"
#include "BUZZER_privet.h"

uint8_t BUZZER_init(const BUZZER_config_t *Copy_BUZZER_obj)
{
	uint8_t Local_u8ErrorState=OK;
	DIO_u8SetPinDirection(Copy_BUZZER_obj->PORT,Copy_BUZZER_obj->Pin_num,DIO_u8_PIN_OUTPUT);
	return Local_u8ErrorState; /*it dose not do any thing at the moment*/
}

uint8_t BUZZER_u8TurnOn(const BUZZER_config_t *Copy_BUZZER_obj)
{
	uint8_t Local_u8ErrorState = OK;
	if (Copy_BUZZER_obj-> ConnType==SRS_conn)   /*check for the connection type*/
	{
		DIO_u8SetPinValue(Copy_BUZZER_obj->PORT,Copy_BUZZER_obj->Pin_num,DIO_u8_PIN_HIGH);
	}
	else if (Copy_BUZZER_obj->ConnType==SINK_conn) /*check for the connection type*/
	{
		DIO_u8SetPinValue(Copy_BUZZER_obj->PORT,Copy_BUZZER_obj->Pin_num,DIO_u8_PIN_LOW);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

uint8_t BUZZER_u8TurnOff(const BUZZER_config_t *Copy_BUZZER_obj)
{
	uint8_t Local_u8ErrorState = OK;
	if (Copy_BUZZER_obj-> ConnType==SRS_conn) /*check for the connection type*/
	{
		DIO_u8SetPinValue(Copy_BUZZER_obj->PORT,Copy_BUZZER_obj->Pin_num,DIO_u8_PIN_LOW);
	}
	else if (Copy_BUZZER_obj->ConnType==SINK_conn) /*check for the connection type*/
	{
		DIO_u8SetPinValue(Copy_BUZZER_obj->PORT,Copy_BUZZER_obj->Pin_num,DIO_u8_PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}