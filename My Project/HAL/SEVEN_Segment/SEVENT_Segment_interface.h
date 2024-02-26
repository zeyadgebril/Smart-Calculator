
/*
 * SEVENT_Segment_interface.h
 *
 * Created: 10/20/2023 9:07:28 PM
 *  Author: Zeyad
 */ 

#ifndef SEVEN_SEGMENT_INTERFACE_H_
#define SEVEN_SEGMENT_INTERFACE_H_


#define COMM_Anod		0
#define COMM_Cathod		1



typedef struct
{
	uint8_t PORT_Pin;
	uint8_t PORT_Enable;
	uint8_t EN1;
	uint8_t EN2;
	uint8_t PinA;
	uint8_t PinB;
	uint8_t PinC;
	uint8_t PinD;
	uint8_t ConnType;
}SEVEN_Segment_config_t;


uint8_t SEVEN_Segment_Display_u8SetNumber( SEVEN_Segment_config_t *Copy_obj,uint8_t Copy_u8Number);

void SEVEN_Segment_Display_u8TurnOn(const SEVEN_Segment_config_t *Copy_obj);

void SEVEN_Segment_Display_u8TurnOff(const SEVEN_Segment_config_t *Copy_obj);


#endif