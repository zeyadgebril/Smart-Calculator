/*
 * CLCD_Interface.c
 *
 * Created: 6/22/2023 5:57:48 AM
 *  Author: UpdateStore
 */ 
#include "CLCD_Privite.h"
/*
* To implement 4_bit mode follow---->
* send Most seg_Bit to D4----->D7 (clcd)
* send enable pulse 
* send lower seg_Bit to D4----->D7 (clcd)
* send enable pulse 
**/

/*implementation of function to take half data from port
****Note: this function is static so  can't use it at any file except CLCD_Interface.c
*/
static void Send_Hlfe_DataPort(uint8_t DATA){ 
	uint8_t Arr_OfCLCDPins[4]={ CLCD_D4 , CLCD_D5 , CLCD_D6 , CLCD_D7 };
		uint8_t Counter;
		/*
		*take first element of data and about array put the value of half data
		**/
		for(Counter=0;Counter<4;Counter++)
		DIO_u8SetPinValue(DATA_PORT,Arr_OfCLCDPins[Counter],GET_BIT(DATA,Counter));
		
}
/*Implement function to send enable pulse*/
static void SendEnablePulse(void){
	DIO_u8SetPinValue(DATA_CTRL,E_PIN,DIO_u8_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(DATA_CTRL,E_PIN,DIO_u8_PIN_LOW);
}
void LCD_SEND_DATA(uint8_t data){
	/*1-SET RS HIGH FOR DATA*/
	DIO_u8SetPinValue(DATA_CTRL,RS_PIN,DIO_u8_PIN_HIGH);
	/*2-SET RW LOW FOR WRITING*/
	DIO_u8SetPinValue(DATA_CTRL,RW_PIN,DIO_u8_PIN_LOW);
	#if CLCD_MODE==Eight_BIT
	/*3-SEND COMMAND*/
	DIO_u8SetPortValue(DATA_PORT,data);
	/*SET PULSE OF ENABLE*/
	SendEnablePulse();
	#elif CLCD_MODE==Four_BIT
	 /*Send High Seg_Bit*/
	 Send_Hlfe_DataPort(data>>4);
	 /*Send Enable Pulse*/
	 SendEnablePulse();
	 /*Send LOW Seg_Bit*/
	 Send_Hlfe_DataPort(data);
	 /*Send Enable Pulse*/
	  SendEnablePulse();
	  #endif	
}
void LCD_SEND_COMMAND(uint8_t command)
{    /*1-SET RS LOW FOR COMMAND*/ 
	    DIO_u8SetPinValue(DATA_CTRL,RS_PIN,DIO_u8_PIN_LOW);
	 /*2-SET RW LOW FOR WRITING*/
	     DIO_u8SetPinValue(DATA_CTRL,RW_PIN,DIO_u8_PIN_LOW);
	 #if CLCD_MODE==Eight_BIT
	 /*3-SEND COMMAND*/
	     DIO_u8SetPortValue(DATA_PORT,command);
     /*SET PULSE OF ENABLE*/
	  SendEnablePulse();
	  #elif  CLCD_MODE==Four_BIT
	  /*Send High Seg_Bit*/
	  Send_Hlfe_DataPort(command>>4);
	  /*Send Enable Pulse*/
	   SendEnablePulse();
	   /*Send LOW Seg_Bit*/
	   Send_Hlfe_DataPort(command);
	   /*Send Enable Pulse*/
	    SendEnablePulse();
		#endif
}
void LCD_INIT(void){  
	/*INIT PINS DIRECTIONS*/
	#if CLCD_MODE==Eight_BIT
	uint8_t counter_8BIT_Mode;
	DIO_u8SetPortDirection(DATA_PORT,DIO_u8_PIN_OUTPUT);
	for(counter_8BIT_Mode =RS_PIN;counter_8BIT_Mode<=E_PIN;counter_8BIT_Mode++)
	DIO_u8SetPinDirection(DATA_CTRL,counter_8BIT_Mode,DIO_u8_PIN_OUTPUT);
	/*Wait for more than 30ms*/
	_delay_ms(40);
	/*function set*/
	LCD_SEND_COMMAND(0b00111000);
	#elif CLCD_MODE==Four_BIT 
	uint8_t counter_data;
	uint8_t counter_ctrl;
	for(counter_data=CLCD_D4 ;counter_data<=CLCD_D7 ;counter_data++)
	 DIO_u8SetPinDirection(DATA_PORT,counter_data,DIO_u8_PIN_OUTPUT);
    for(counter_ctrl =RS_PIN;counter_ctrl<=E_PIN;counter_ctrl++)
     DIO_u8SetPinDirection(DATA_CTRL,counter_ctrl,DIO_u8_PIN_OUTPUT);
	 /*Wait for more than 30ms */
	 _delay_ms(40);
	/* function set of 4_bit*/
	Send_Hlfe_DataPort(0b0010);
	/*send enable pulse*/
	  SendEnablePulse();
	  Send_Hlfe_DataPort(0b0010);
	  SendEnablePulse();
	  Send_Hlfe_DataPort(0b1000);
	  SendEnablePulse();
	#endif 
	/*Display ON/OFF Control Display on , cursor off ,blink off*/
	LCD_SEND_COMMAND(0b00001100);
	/*Display Clear */
	LCD_SEND_COMMAND(1);
	
}
void LCD_SEND_STRING(uint8_t*str){    
	while (*str!='\0'){
		LCD_SEND_DATA(*str);
		str++;
	}
} 
  void LCD_SEND_DICNUMBER(sint32_t number){ 
	/*Counter*/
	uint8_t i=0,j;
	/*Store To Reverse Data*/
	uint8_t arr[10]={0};
	if(number==0){
	LCD_SEND_DATA('0');}
	/*if(number<0)
	{
		LCD_SEND_DATA('-');
		number=-1*number;
	}*/
		while (number){//12
			arr[i]=number%10+'0';
			number/=10;
			i++;
		} 
		for(j=i;j>0;j--)
		LCD_SEND_DATA(arr[j-1]);//arr[1,2];
} 
void LCD_SEND_NUMBER(fint64_t Number){
	if(Number<0){
		LCD_SEND_DATA('-');
		Number=Number*-1;
	}  //13.3
	
	sint32_t num=Number;
	if(Number-num!=0){
		LCD_SEND_DICNUMBER(num);
		LCD_SEND_DATA('.');
		LCD_SEND_DICNUMBER((Number-num)*10);	
	} else 
	LCD_SEND_DICNUMBER(num);//13
}
void LCD_SetCursor(uint8_t ROW,uint8_t COL){
	uint8_t DDRAM_ADDRESS;
	switch(COL){
		case 0:DDRAM_ADDRESS=ROW;           break;
		case 1:DDRAM_ADDRESS=ROW+0x40;	    break;
		default:   /*Do Nothing*/           break;
	}
	/* Anther way*
	*DDRAM_ADD=col*0x40+row;(1,0);
	*/
	/*set bit 7 to set DDRAM Command*/
	SET_BIT(DDRAM_ADDRESS,7);
	/*set DDRAM Command to determined location*/
	LCD_SEND_COMMAND(DDRAM_ADDRESS);
} 
void LCD_SpecialChar(uint8_t *arrofchar,uint8_t patt,uint8_t ROW,uint8_t COL){
uint8_t Itrator;
/*Starting Calculating CGRAM Address*/
uint8_t CGRAM_Adress=8*patt;
/*Set Bit Number 6 and Clear Bit Number 7 For CGRAM */
SET_BIT(CGRAM_Adress,6);
/*Send Command TO Write AT CGRAM*/
LCD_SEND_COMMAND(CGRAM_Adress);
/*Looping To store Data At CGRAM*/
for(Itrator=0;Itrator<8;Itrator++){
LCD_SEND_DATA(arrofchar[Itrator]);
}
/*Set DDRAM Address*/
LCD_SetCursor(ROW,COL);
/*Display Data About DDRAM*/
LCD_SEND_DATA(patt);
}
void LCD_ScrollRight(void){
	
	LCD_SEND_COMMAND(0x1c);
} 
void LCD_ScrollLeft(void){
	
	LCD_SEND_COMMAND(0x18);

}
void LCD_CLear(void){
	LCD_SEND_COMMAND(0x01);
}

