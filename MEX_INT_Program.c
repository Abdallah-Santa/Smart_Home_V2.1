#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"MEX_INT_Private.h"
#include"MDIO_INTERFACE.h"
#include<avr/delay.h>


/*Initialize External Interrupt 0*/
void MINT0_VoidInit(void)
{
	
	SET_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);

}


/*Enable External Interrupt 0*/
void MINT0_VoidEn(void)
{
	SET_BIT(GICR,6);
	
}


/*Disable External Interrupt 0*/
void MINT0_VoidDis(void)
{
	
	CLR_BIT(GICR,6);
}
/*Interrupt Function 1 */
void __vector_1(void)
{
	for(u8 i=0;i<=3;i++)
{
	MDIO_VoidTogglePin(3,0);
	_delay_ms(1000);
}
}
/*Initialize External Interrupt 1*/
void MINT1_VoidInit(void)
{

	SET_BIT(MCUCR,3);
	CLR_BIT(MCUCR,2);

}

/*Enable External Interrupt 1*/
void MINT1_VoidEn(void)
{
	SET_BIT(GICR,7);

}

/*Disable External Interrupt 0*/
void MINT1_VoidDis(void)
{

	CLR_BIT(GICR,7);
}


/*Interrupt Function 2 */
void __vector_2(void)
{
for(u8 y=0;y<=3;y++)
{
	MDIO_VoidTogglePin(3,4);
	_delay_ms(1000);
}
}
