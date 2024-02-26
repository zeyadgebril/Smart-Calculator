/*
 * CLCD_Privite.h
 *
 * Created: 6/22/2023 5:57:23 AM
 *  Author: UpdateStore
 */ 


#ifndef CLCD_PRIVITE_H_
#define CLCD_PRIVITE_H_
#include "CLCD_CONFIGURATION.h"
void LCD_SEND_DATA(uint8_t data);
void LCD_SEND_COMMAND(uint8_t command);
void LCD_INIT(void);
void LCD_SEND_STRING(uint8_t*str);
void LCD_SEND_DICNUMBER(sint32_t Number);
void LCD_SEND_NUMBER(fint64_t Number);
void LCD_SetCursor(uint8_t ROW,uint8_t COL);
void LCD_CLear(void);
void LCD_ScrollRight(void);
void LCD_ScrollLeft(void);
void LCD_SpecialChar(uint8_t *arrofchar,uint8_t patt,uint8_t ROW,uint8_t COL);
//void lcdScrollUp(Uint32_t  delay_ms );
	
	


/*void CLCD_voidSendCmd(Uint8_t Copy_u8Cmd);
void CLCD_voidSendData(char Copy_c8Data);

Uint8_t CLCD_u8SendString(const char *Copy_ch8String);
void CLCD_voidSendDecimalNumber(Sint32_t Copy_s32Number);
void CLCD_voidInit(void);*/






#endif /* CLCD_PRIVITE_H_ */