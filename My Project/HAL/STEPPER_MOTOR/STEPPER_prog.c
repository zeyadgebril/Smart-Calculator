
/*
 * STEPPER_prog.c
 *
 * Created: 11/1/2023 12:32:44 AM
 *  Author: Zeyad
 */ 

#include "Configurations.h"

#include "STEPPER_config.h"
#include "STEPPER_interface.h"
#include "STEPPER_privet.h"

static const uint8_t FullStep_Arr[4] = { 0x09 , 0x0c , 0x06 , 0x03 };
static const uint8_t HalfStep_Arr[4] = { 0x09 , 0x08 , 0x0c , 0x04 , 0x06 , 0x02 , 0x03 , 0x01};
static const uint8_t Period = 100;

void STEPPER_voidInit(void)
{
	DIO_u8SetPinDirection(STEPPER_U8_PORT,STEPPER_u8_APluse,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_U8_PORT,STEPPER_u8_AMinus,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_U8_PORT,STEPPER_u8_BPluse,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_U8_PORT,STEPPER_u8_BMinus,DIO_u8_PIN_OUTPUT);
	
	DIO_u8SetPortValue(STEPPER_U8_PORT,0X09); 
	//Initial position for the stepper motor
}

uint8_t STEPPER_u8Rotate(uint8_t Copy_u8Step, uint8_t Copy_u8Direction)
{
	uint8_t Local_u8ErrorState = OK;
	uint8_t Local_u8_counter = 0;
	
	if(Copy_u8Direction == STEP_CCW)
	{
		if (Copy_u8Step == FULL_STEP)
		{
			for(Local_u8_counter = 0 ; Local_u8_counter < 4 ; Local_u8_counter ++)
			{
				DIO_u8SetPortValue(STEPPER_U8_PORT,FullStep_Arr[Local_u8_counter]); 
				_delay_ms(Period);
			}
		}
		else if(Copy_u8Step == HALF_STEP)
		{
			for(Local_u8_counter = 0 ; Local_u8_counter < 8 ; Local_u8_counter ++)
			{
				DIO_u8SetPortValue(STEPPER_U8_PORT,HalfStep_Arr[Local_u8_counter]);
				_delay_ms(Period);
			}
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	else if(Copy_u8Direction == STEP_CW )
	{
		if (Copy_u8Step == FULL_STEP)
		{
			for(Local_u8_counter = 3 ; Local_u8_counter >= 0 ; Local_u8_counter --)
			{
				DIO_u8SetPortValue(STEPPER_U8_PORT,FullStep_Arr[Local_u8_counter]);
				_delay_ms(Period);
			}
		}
		else if(Copy_u8Step == HALF_STEP)
		{
			for(Local_u8_counter = 7 ; Local_u8_counter >=0 ; Local_u8_counter --)
			{
				DIO_u8SetPortValue(STEPPER_U8_PORT,HalfStep_Arr[Local_u8_counter]);
				_delay_ms(Period);
			}
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	
	else
	{
		Local_u8ErrorState = NOK;
	}
	
	_delay_ms(125);
	
	return Local_u8ErrorState;
}

void STEPPER_voidBreak(void)
{
	DIO_u8SetPortValue(STEPPER_U8_PORT,0X00);
	_delay_ms(125);
	DIO_u8SetPortValue(STEPPER_U8_PORT,0X09);

}