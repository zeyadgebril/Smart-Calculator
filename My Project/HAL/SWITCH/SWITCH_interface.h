
/*
 * SWITCH_interface.h
 *
 * Created: 10/20/2023 7:50:32 PM
 *  Author: Zeyad
 */ 

#define Pull_up		0
#define Pull_down	1

typedef struct
{
	uint8_t PORT;
	uint8_t Pin_num;
	uint8_t PullType;
	
}Switch_config_t;

void Switch_u8Init(const Switch_config_t *Copy_SWITCH_obj);

uint8_t Switch_u8GetState(const Switch_config_t *Copy_SWITCH_obj,uint8_t *Copy_pu8State);
