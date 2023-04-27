#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"MGIE_Private.h"



void GIE_VoidEn(void)
{
	
	SET_BIT(SREG,7);
	
}
void GIE_VoidDis(void)
{
	
	CLR_BIT(SREG,7);
	
}
