/*
 * BUZZER_interface.h
 *
 * Created: 10/20/2023 4:38:27 AM
 *  Author: Zeyad
 */ 
#define SRS_conn	0
#define SINK_conn	1


typedef struct
{
	uint8_t PORT;
	uint8_t Pin_num;
	uint8_t ConnType;
}BUZZER_config_t;

uint8_t BUZZER_init(const BUZZER_config_t *Copy_LED_obj);

uint8_t BUZZER_u8TurnOn(const BUZZER_config_t *Copy_LED_obj);

uint8_t BUZZER_u8TurnOff(const	BUZZER_config_t *Copy_LED_obj);
