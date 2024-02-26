/*
 * My Project.c
 *
 * Created: 10/13/2023 6:32:29 AM
 * Author : Zeyad
 */ 
#include "main.h"



 int main(void)
 {

    uint8_t local_u8PressedKey = 0xff;	//Initialize the Pull up res in the MC for the keypad
	uint8_t local_u8Counter=1;			// position of the written number 
	uint8_t local_u8Num1=0;				// get the first number 
	uint8_t local_u8Num2=0;				// get the second number
	uint8_t local_u8Operation=0;				// get the operation that will happened 
	uint8_t local_u8FlagGetNum2=0;				// flag to know when to get the second number 
	uint8_t local_u8FlagGetNum1=1;				// flag to know when to get the first number 
	fint64_t local_u8FinalResult=0;				// storage for the result of the calculator
	fint64_t local_u8FlagRationalNumber=0;				// storage for the result of Rational number that might happened cuz of the devision 
	fint64_t local_u8Temp=0;				// empty variable for the operation 

  	 KPD_voidInit();
  	 LCD_INIT();
	   
     LCD_SetCursor(1,0);
	 LCD_SEND_STRING(" CALLCULATOR");
	

 
 while(1)
 {
	 
	 LCD_SetCursor(1,0);
	 LCD_SEND_STRING(" CALLCULATOR");
	 
	do 
  	{
  	 local_u8PressedKey = KPD_u8GetPressedKey();   /* Get the pressed number*/
  	} while (local_u8PressedKey == 0xff);
	  
	  
  /*  to print the number on the LCD*/
  if(local_u8PressedKey<10)
  {
	  LCD_SetCursor(local_u8Counter,1);
	  LCD_SEND_NUMBER(local_u8PressedKey);
	  local_u8Counter++;
	  if(local_u8FlagGetNum1==1)
	  {
	  local_u8Num1=(local_u8Num1*10)+local_u8PressedKey;
	  }
  }
	else if(local_u8PressedKey>9 && local_u8PressedKey!='c')	  /* show the figure on LCD */
	  {  
		 LCD_SetCursor(local_u8Counter,1);
		 LCD_SEND_DATA(local_u8PressedKey);
		 
		 local_u8Counter++;
		 local_u8FlagGetNum1=0;
		
		 
	  }
 /* get the second number */
 if(local_u8FlagGetNum2==1&&local_u8PressedKey!='=')
 {
	 local_u8Num2=(local_u8Num2*10)+local_u8PressedKey;
 }
 
 /* get type of operation that will happen*/
 switch(local_u8PressedKey)
 {
	 case '+':
	 local_u8Operation='+';
	 local_u8FlagGetNum2=1;
	 break;
	 case '-':
	 local_u8Operation='-';
	  local_u8FlagGetNum2=1;
	 break;
	 case 'x':
	 local_u8Operation='x';
	  local_u8FlagGetNum2=1;
	 break;
	 case '/':
	 local_u8Operation='/';
	  local_u8FlagGetNum2=1;
	 break;
	 
 }
  
  /* make the operation and print it */
  if(local_u8PressedKey =='=')
  {
	switch(local_u8Operation)
	{
		case 'x':
		local_u8FinalResult=local_u8Num1*local_u8Num2;
		local_u8Counter++;
		LCD_SEND_NUMBER(local_u8FinalResult);
		break;
		case '+':
		local_u8FinalResult=local_u8Num1+local_u8Num2;
		local_u8Counter++;
		LCD_SEND_NUMBER(local_u8FinalResult);
		break;
		case '-':
		local_u8FinalResult=local_u8Num1-local_u8Num2;
		local_u8Counter++;
		LCD_SEND_NUMBER(local_u8FinalResult);
		break;
		case '/':
		local_u8Temp=local_u8Num1/local_u8Num2;
		local_u8FinalResult=local_u8Num1/local_u8Num2;
		
		if((local_u8Temp-local_u8FinalResult)>0)
		{
		local_u8FlagRationalNumber=1;	
		local_u8Temp-=local_u8FinalResult;
		}
		if(local_u8Num2!=0)
		{
			local_u8Counter++;
			LCD_SEND_NUMBER(local_u8FinalResult);
			if(local_u8FlagRationalNumber==1)   //print the rational number 
			{
				LCD_SEND_DATA('.');
				local_u8Temp*=100;
				LCD_SEND_NUMBER(local_u8Temp);
			}
			
		}
		else {
		LCD_CLear();
	    LCD_SetCursor(1,0);
		LCD_SEND_STRING(" CALLCULATOR");
		LCD_SetCursor(1,1);
		LCD_SEND_STRING("Error");
		}
		break;
		
		
	}
	
  }
  
  
 
  
  /*  to clear the numbers on the LCD and initialize the calculator again */
  if(local_u8PressedKey=='c')
  {
	LCD_CLear();
    LCD_SetCursor(1,0);
 LCD_SEND_STRING(" CALLCULATOR");
 local_u8Counter = 1;
 local_u8Num1=0;
 local_u8Num2=0;
 local_u8Operation=0;
 local_u8FlagGetNum2=0;
 local_u8FinalResult=0;
 local_u8FlagGetNum1=1;				
 


  }
  
 
	  }
 }


 

