
/*
 * STEPPER_interface.h
 *
 * Created: 11/1/2023 12:32:17 AM
 *  Author: Zeyad
 */ 
#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

#define  STEP_CW	0
#define  STEP_CCW	1

#define  FULL_STEP	3
#define  HALF_STEP	4

void STEPPER_voidInit(void);

uint8_t STEPPER_u8Rotate(uint8_t Copy_u8Step, uint8_t Copy_u8Direction);

void STEPPER_voidBreak(void);

#endif
