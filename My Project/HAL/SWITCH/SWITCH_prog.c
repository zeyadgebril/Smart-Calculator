
/*
 * SWITCH_prog.c
 *
 * Created: 10/20/2023 7:51:15 PM
 *  Author: Zeyad
 */ 
#include "Configurations.h"

#include "SWITCH_config.h"
#include "SWITCH_interface.h"
#include "SWITCH_privet.h"

void Switch_u8Init(const Switch_config_t *Copy_SWITCH_obj)
{
	DIO_u8SetPinDirection(Copy_SWITCH_obj->PORT,Copy_SWITCH_obj->Pin_num,DIO_u8_PIN_INPUT);
}

uint8_t Switch_u8GetState(const Switch_config_t *Copy_SWITCH_obj,uint8_t *Copy_pu8State)
{
		uint8_t Local_u8ErrorState = OK;
		if (Copy_SWITCH_obj->PullType==Pull_down)
		{
			DIO_u8GetPinValue(Copy_SWITCH_obj->PORT,Copy_SWITCH_obj->Pin_num,*Copy_pu8State);
		}
	return Local_u8ErrorState;
}