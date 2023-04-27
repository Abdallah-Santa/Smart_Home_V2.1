                       



/*
					    ************************************************************************
 						**                Created on: Sep 10, 2021                            **
                        **                Author: Abdallah Taha                               **           
						**                File Name : HLCD_Program                            **
						**                 V 1.0                                              **
						**                Description: LCD Driver                             **
						**                                                                    **
						**                                                                    **
						************************************************************************/








#include"STD_TYPES.h"
#include "MDIO_INTERFACE.h"
#include "HLCD_Config.h"
#include <util/delay.h>
 

void HLCD_VoidSendChar(u8 Copy_U8Data)
{
	 /*Set Rs=1 , to send data*/
    MDIO_VoidSetPinValue(HLCD_Rs_Port,0,1);
	
	/*Set Rw=0 , to write on LCD*/
	MDIO_VoidSetPinValue(HLCD_Rw_Port,1,0); 
	
	 /*Write Data On LCD*/
	MDIO_VoidSetPortValue(HLCD_DataPort,Copy_U8Data);
	
	/*set low to enable*/
	MDIO_VoidSetPinValue(HLCD_EN_Port,2,0); 
	
	/*wait 1 ms*/
	
	_delay_ms(1); 
	
	 /*set Hi to enable*/
	MDIO_VoidSetPinValue(HLCD_EN_Port,2,1);
	
	 /*wait 1 ms*/
	_delay_ms(1);
	
	 /*set low to ennable*/
	MDIO_VoidSetPinValue(HLCD_EN_Port,2,0);
	
	/*wait 1 ms*/
	_delay_ms(2);
}
void HLCD_VoidSendCommand(u8 Copy_U8Command)
{
	/*Set Rs=0 , to send command*/
	MDIO_VoidSetPinValue(HLCD_Rs_Port,0,0);
	
	/*Set Rw=0 , to write on LCD*/
	MDIO_VoidSetPinValue(HLCD_Rw_Port,1,0);
	
	  /*DO command On LCD*/
	MDIO_VoidSetPortValue(HLCD_DataPort,Copy_U8Command);
	
	/*set low to enable*/
	MDIO_VoidSetPinValue(HLCD_EN_Port,2,0);
	
	 /*wait 1 ms*/
	_delay_ms(1);
	
	/*set Hi to enable*/
	MDIO_VoidSetPinValue(HLCD_EN_Port,2,1);
	
	 /*wait 1 ms*/
	_delay_ms(1);
	
	/*set low to enable*/
	MDIO_VoidSetPinValue(HLCD_EN_Port,2,0);
	
	/*wait 1 ms*/
	_delay_ms(2);
	
}
void HLCD_VoidInit(void)
{
	/*Set Direction Of alla Pins*/
	
	MDIO_VoidSetPortDirection(HLCD_DataPort,0xff);
	MDIO_VoidSetPinDirection(HLCD_Rs_Port,0,1);
	MDIO_VoidSetPinDirection(HLCD_Rw_Port,1,1);
	MDIO_VoidSetPinDirection(HLCD_EN_Port,2,1);
	
		/*wait more than 30ms*/
	_delay_ms(40);
	
	/*Function Set (Set No.of Lines & Font Type*/
	HLCD_VoidSendCommand(0b00111000);

    /*Wait More Than 39us*/
    _delay_us(45);
	
	/*Display ON/OFF Control*/
	HLCD_VoidSendCommand(0b00001110);
	
	/*Wait More Than 39us*/
    _delay_us(45);
	
	/*Display Clear*/
	HLCD_VoidSendCommand(0b00000001);
	
		/*wait more than 1.53ms*/
	_delay_ms(2);
	
	
	/*Entry Mode Set Ù…Ø´ Ù„Ø§Ø²Ù…*/
	/*HLCD_VoidSendCommand(0b000001IS);*/
	
	
}

void HLCD_VoidInit4Bit(void)
{
	/*Set Direction Of alla Pins*/
	
	MDIO_VoidSetPortDirection(HLCD_DataPort,0xff);
	MDIO_VoidSetPinDirection(HLCD_Rs_Port,0,1);
	MDIO_VoidSetPinDirection(HLCD_Rw_Port,1,1);
	MDIO_VoidSetPinDirection(HLCD_EN_Port,2,1);
	
	
	/*wait more than 30ms*/
	_delay_ms(40);
	
	/*Function Set */
	HLCD_VoidSendCommand(0b00100000);
	
	/*Function Set */
	HLCD_VoidSendCommand(0b00100000);
    

	/*Function Set (Set No.of Lines & Font Type*/
	HLCD_VoidSendCommand(0b11000000);
	
	 /*Wait More Than 39us*/
    _delay_us(45);
	
	/*Display ON/OFF Control*/
    HLCD_VoidSendCommand(0b00000000);
	HLCD_VoidSendCommand(0b11110000);
	
	/*Wait More Than 39us*/
    _delay_us(45);
	
	/*Display Clear*/
	HLCD_VoidSendCommand(0b00000000);
	HLCD_VoidSendCommand(0b00010000);
	
	
	_delay_ms(10);
	
	
	
	
}

void HLCD_VoidSendString(u8* Coby_U8String)
{
	/*Lentgh Of String*/
	u8 LOC_LENGTH = 0;
	
	
	/*Do Until String End*/
	while(Coby_U8String[LOC_LENGTH]!=('\0'))
	{
		
		
		/*Send Character as String*/
		HLCD_VoidSendChar(Coby_U8String[LOC_LENGTH]);
		
		/*Increment Length*/
		LOC_LENGTH++;
	}
	
	
}

void HLCD_VoidSetPostion(u8 Copy_U8Row,u8 Copy_U8Colm)
{
	
	/*If U Want The First Row*/
	if(0==Copy_U8Row)
	{
	
        /*Enter Colm NO. U Want To Display On It*/	
		HLCD_VoidSendCommand(Copy_U8Colm+128);
	
		
	}
	
	/*If U Want The Second Row*/
	else if(1==Copy_U8Row)
	{
		
		
        /*Enter Colm NO. U Want To Display On It*/	
			HLCD_VoidSendCommand(Copy_U8Colm+128+64);
				

	}
	
	
}
void HLCD_VoidSendNumber(u32 Copy_U8Number)
{
	if(0==Copy_U8Number)
	{
		HLCD_VoidSendChar(0+48);
	}
	else
	{
	u32 LOC_Rev =1;
	while(Copy_U8Number)
	{
		LOC_Rev = (LOC_Rev*10)+ Copy_U8Number%10;
		Copy_U8Number /=10 ;
		
		
	}
	while(LOC_Rev>1)
	{
		Copy_U8Number = LOC_Rev%10;
		HLCD_VoidSendChar(Copy_U8Number+48);
		LOC_Rev = LOC_Rev /10;
		
	}
		
	}
	
}

void HLCD_VoidDrawChar(void)
{
	
	HLCD_VoidSendCommand(0b01000000);
	HLCD_VoidSendChar(0b00111);
	HLCD_VoidSendChar(0b01000);
	HLCD_VoidSendChar(0b01000);
	HLCD_VoidSendChar(0b00111);
	HLCD_VoidSendChar(0b00100);
	HLCD_VoidSendChar(0b00100);
	HLCD_VoidSendChar(0b00111);
	HLCD_VoidSendCommand(128+1);
	HLCD_VoidSendChar(0b00000000);
	
	
	
	
}
