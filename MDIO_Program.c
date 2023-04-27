/*                      ************************************************************************
 						**               Created on: Aug 20, 2021                             **
                        **                Author: Abdallah Taha                               **           
						**                File Name : MDIO_Program                            **
						**                 V 1.0                                              **
						**         Description: Driver For MDIO                               **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						************************************************************************/





#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_Private.h"
#include"MDIO_Interface.h"







void MDIO_VoidSetPinDirection(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Direction)
{
	if(1== Copy_U8Direction)
	{
		switch(Copy_U8Port)
		{
			case 0 : SET_BIT(DDRA_REG,Copy_U8Pin);
			break;
			case 1 : SET_BIT(DDRB_REG,Copy_U8Pin);
			break;
			case 2 : SET_BIT(DDRC_REG,Copy_U8Pin);
			break;
			case 3 : SET_BIT(DDRD_REG,Copy_U8Pin);
			break;
			default : /*Do Nothing*/;
			
			
			
		}
	}
	else if(0== Copy_U8Direction)
	{
				switch(Copy_U8Port)
		{
			case 0 : CLR_BIT(DDRA_REG,Copy_U8Pin);break;
			case 1 : CLR_BIT(DDRB_REG,Copy_U8Pin);break;
			case 2 : CLR_BIT(DDRC_REG,Copy_U8Pin);break;
			case 3 : CLR_BIT(DDRD_REG,Copy_U8Pin);break;
			default : /*Do Nothing*/;
			
			
			
		}
	}
	else
	{
		
	/*Do Nothing*/	
	}
	
}
u8 MDIO_u8GetPinValue(u8 Copy_U8Port ,u8 Copy_U8Pin )
{
	u8 Loc_U8RetValue;
	
	switch(Copy_U8Port)
	{
		case 0: Loc_U8RetValue=GET_BIT(PINA_REG,Copy_U8Pin);break;
		case 1: Loc_U8RetValue=GET_BIT(PINB_REG,Copy_U8Pin);break;
		case 2: Loc_U8RetValue=GET_BIT(PINC_REG,Copy_U8Pin);break;
		case 3: Loc_U8RetValue=GET_BIT(PIND_REG,Copy_U8Pin);break;
	
		
	}
	return Loc_U8RetValue;
	
}
void MDIO_VoidSetPinValue(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Value)
{
	
	if(0==Copy_U8Value)
	{
		switch(Copy_U8Port)
		{
			case 0 : CLR_BIT(PORTA_REG,Copy_U8Pin);break;
			case 1 : CLR_BIT(PORTB_REG,Copy_U8Pin);break;
			case 2 : CLR_BIT(PORTC_REG,Copy_U8Pin);break;
			case 3 : CLR_BIT(PORTD_REG,Copy_U8Pin);break;
			default:/*Do Nothing*/;
			
		}
		
	}
	else if(1==Copy_U8Value)
	{
				switch(Copy_U8Port)
		{
			case 0 : SET_BIT(PORTA_REG,Copy_U8Pin);break;
			case 1 : SET_BIT(PORTB_REG,Copy_U8Pin);break;
			case 2 : SET_BIT(PORTC_REG,Copy_U8Pin);break;
			case 3 : SET_BIT(PORTD_REG,Copy_U8Pin);break;
			default:/*Do Nothing*/;
			
		}
		
	}
	else
	{
		/*Do Nothing*/
	}
	
	
	
}
void MDIO_VoidSetPortDirection(u8 Copy_U8Port ,u8 Copy_U8Direction)
{
	
	
		switch(Copy_U8Port)
		{
			
			case 0 : DDRA_REG=Copy_U8Direction;break;
			case 1 : DDRB_REG=Copy_U8Direction;break;
			case 2 : DDRC_REG=Copy_U8Direction;break;
			case 3 : DDRD_REG=Copy_U8Direction;break;
			default:/*Do Nothing*/;
			
			
		}
		
		
		
	
	
	
	
	
	
	
}
void MDIO_VoidSetPortValue(u8 Copy_U8Port ,u8 Copy_U8Value)
{
	
		switch(Copy_U8Port)
		{
			case 0 : PORTA_REG =Copy_U8Value;break;
			case 1 : PORTB_REG =Copy_U8Value;break;
			case 2 : PORTC_REG =Copy_U8Value;break;
			case 3 : PORTD_REG =Copy_U8Value;break;
			default:/*Do Nothing*/;
			
			
		}
		
		
	
	
	
}

void MDIO_VoidTogglePin(u8 Copy_U8Port ,u8 Copy_U8Pin )
{
	
	switch(Copy_U8Port)
	{
		case 0 : TOGGLE_BIT(PORTA_REG,Copy_U8Pin);break;
		case 1 : TOGGLE_BIT(PORTB_REG,Copy_U8Pin);break;
		case 2 : TOGGLE_BIT(PORTC_REG,Copy_U8Pin);break;
		case 3 : TOGGLE_BIT(PORTD_REG,Copy_U8Pin);break;
		default:/*Do Nothing*/;
		
		
		
	}
	
}
