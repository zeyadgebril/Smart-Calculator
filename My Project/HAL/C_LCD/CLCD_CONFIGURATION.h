/*******************************************************************/
 /************************************* CLCD_CONFIGURATION.h*******/
 /****************************** Created: 6/22/2023 5:56:46 AM*/
 /********************************* Author:Abdelrhman ****/ 

/*****************File_Garde*********************/
#ifndef CLCD_CONFIGURATION_H_
#define CLCD_CONFIGURATION_H_
#include "Configurations.h"
/*define LCD modes*/
	#define Four_BIT  0        /*D4------->D7*/
	#define Eight_BIT 1       /*D1-------->D7*/
	
	/**
	** options
	1-Four_BIT
	2-Eight_BIT
	**/
#define  CLCD_MODE    Four_BIT  
#define  DATA_PORT    DIO_u8_PORTA


#if CLCD_MODE==Four_BIT 
#define CLCD_D4  DIO_u8_PIN4 
#define CLCD_D5  DIO_u8_PIN5
#define CLCD_D6  DIO_u8_PIN6
#define CLCD_D7  DIO_u8_PIN7
#endif

#define DATA_CTRL    DIO_u8_PORTB
#define RS_PIN       DIO_u8_PIN1
#define RW_PIN       DIO_u8_PIN2
#define E_PIN        DIO_u8_PIN3





#endif /* CLCD_CONFIGURATION_H_ */