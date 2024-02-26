/*
 * LED_interface.h
 *
 * Created: 10/20/2023 3:35:57 AM
 *  Author: Zeyad
 */ 
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_



#define SRS_conn	0
#define SINK_conn	1


typedef struct
{
	uint8_t PORT;
	uint8_t Pin_num;
	uint8_t ConnType;
}LED_config_t;

void LED_u8Init(const LED_config_t *Copy_LED_obj);

uint8_t LED_u8TurnOn(const LED_config_t *Copy_LED_obj);

uint8_t LED_u8TurnOff(const	LED_config_t *Copy_LED_obj);

#endif