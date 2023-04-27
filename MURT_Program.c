#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MURT_Private.h"

void URT_Init(void)
{
	static u8 LOC_UBRR_Help=0;
	/*Select Register */
	SET_BIT(LOC_UBRR_Help,7);
	
	/*Enable Recevier*/
	SET_BIT(UCSRB,4);
	
	/*Enable Transmitter*/
	SET_BIT(UCSRB,3);
	
	/*Select Mode (A Synch)*/
	CLR_BIT(LOC_UBRR_Help,6);
	
	/*Select Parity Mode(Disable)*/
	CLR_BIT(LOC_UBRR_Help,5);
	CLR_BIT(LOC_UBRR_Help,4);
	
	/*Stop Bit Select (1 Bit)*/
	CLR_BIT(LOC_UBRR_Help,3);
	
	/*Select Character Size (8 Bit)*/
	CLR_BIT(UCSRB,2);
	SET_BIT(LOC_UBRR_Help,2);
	SET_BIT(LOC_UBRR_Help,1);
	
	/*Select BAUD Rate*/
	UBRR=51;
	
	UCSRC=LOC_UBRR_Help;
	
	
}

void URT_Transmitte(u8 Copy_U8Data)
{
		UDR=Copy_U8Data;
	while(GET_BIT(UCSRA,5)==0);

	
}

u8 URT_Recevier(void)
{
	while(GET_BIT(UCSRA,7)==0);
	return UDR;
	
}

void URT_SendString(u8* Coby_U8String)
{

	/*Lentgh Of String*/
		u8 LOC_LEGNTH = 0;


		/*Do Until String End*/
		for(LOC_LEGNTH=0;Coby_U8String[LOC_LEGNTH];LOC_LEGNTH++)
		{


			/*Send Character as String*/
			URT_Transmitte(Coby_U8String[LOC_LEGNTH]);

			/*Increment Length*/

		}
}
