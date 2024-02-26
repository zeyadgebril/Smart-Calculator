
/*
 * KEYPAD_prog.c
 *
 * Created: 10/28/2023 4:17:05 AM
 *  Author: Zeyad
 */ 

#include "Configurations.h"

#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_privet.h"

void KPD_voidInit(void)
{
	uint8_t Local_u8Counter;
	for(Local_u8Counter = KPD_u8_R0_PIN ; Local_u8Counter <= KPD_u8_R3_PIN ; Local_u8Counter++)
	DIO_u8SetPinDirection(KPD_U8_PORT,Local_u8Counter,DIO_u8_PIN_INPUT);
	
	for(Local_u8Counter = KPD_u8_C0_PIN ; Local_u8Counter <= KPD_u8_C3_PIN ; Local_u8Counter++)
	DIO_u8SetPinDirection(KPD_U8_PORT,Local_u8Counter,DIO_u8_PIN_OUTPUT);
	
	DIO_u8SetPortValue(KPD_U8_PORT,0xff);
}

uint8_t KPD_u8GetPressedKey(void)
{
	uint8_t Local_u8ColumnIdx,Local_u8RowIdx,Local_u8PinState,Local_u8PressedKey=KPD_u8_NO_PRESSED_KEY_VAL;
	
	uint8_t Local_u8ColArr[KPD_u8_COL_NUM]={KPD_u8_C0_PIN,KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN};
	uint8_t Local_u8RowArr[KPD_u8_ROW_NUM]={KPD_u8_R0_PIN,KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN};
		
	uint8_t Local_KpdArr[KPD_u8_ROW_NUM][KPD_u8_COL_NUM] = KPD_u8_BUTTON_VAL;

	for(Local_u8ColumnIdx = 0 ; Local_u8ColumnIdx < KPD_u8_COL_NUM ; Local_u8ColumnIdx++)
	{
		/* Activate the current column */
		DIO_u8SetPinValue(KPD_U8_PORT,Local_u8ColArr[Local_u8ColumnIdx],DIO_u8_PIN_LOW);
		for(Local_u8RowIdx = 0 ; Local_u8RowIdx < KPD_u8_ROW_NUM; Local_u8RowIdx++)
		{
			/*Read the current row*/
			DIO_u8GetPinValue(KPD_U8_PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8PinState);
			
			/*check if a button is pressed*/
			
			if(Local_u8PinState == DIO_u8_PIN_LOW)
			{
				Local_u8PressedKey = Local_KpdArr[Local_u8RowIdx][Local_u8ColumnIdx];
				
				/*wait until the key is released(polling or busy waiting)*/
				while(Local_u8PinState == DIO_u8_PIN_LOW)
				{
					DIO_u8GetPinValue(KPD_U8_PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8PinState);
				}
				
				return Local_u8PressedKey;
			}
		}
		
		/* Deactivate the current column*/
		DIO_u8SetPinValue(KPD_U8_PORT,Local_u8ColArr[Local_u8ColumnIdx],DIO_u8_PIN_HIGH);
	}
	
	return Local_u8PressedKey;
}