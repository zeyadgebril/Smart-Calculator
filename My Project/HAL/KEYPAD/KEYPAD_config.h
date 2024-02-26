
/*
 * KEYPAD_config.h
 *
 * Created: 10/28/2023 4:16:07 AM
 *  Author: Zeyad
 */ 
#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KPD_U8_PORT		DIO_u8_PORTC

#define KPD_u8_R0_PIN	DIO_u8_PIN0
#define KPD_u8_R1_PIN	DIO_u8_PIN1
#define KPD_u8_R2_PIN	DIO_u8_PIN2
#define KPD_u8_R3_PIN	DIO_u8_PIN3
			
#define KPD_u8_C0_PIN	DIO_u8_PIN4
#define KPD_u8_C1_PIN	DIO_u8_PIN5
#define KPD_u8_C2_PIN	DIO_u8_PIN6
#define KPD_u8_C3_PIN	DIO_u8_PIN7
		
#define KPD_u8_BUTTON_VAL  {{7,8,9,'/'},{4,5,6,'x'},{1,2,3,'-'},{'c',0,'=','+'}}

#define  KPD_u8_ROW_NUM		4
#define  KPD_u8_COL_NUM		4

#define KPD_u8_NO_PRESSED_KEY_VAL		0xff


#endif