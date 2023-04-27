#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MTimer_Private.h"
#include "MTimer_Config.h"
#include "MDIO_Interface.h"
static void(*TIM0_CB)(void);
u8 OV_Count1=0;
u8 Flag=0;
u16 Snap1=0;
u32 Snap2=0;
u32 Snap3=0;
void TIM0_Init(void)
{
	#if TIMER0_MODE==NORMAL_MODE
	/*Select Mode (Normal)*/
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	#if TIMER0_OV_INTERRUPT==ENABLE
	/*Enable OVER Flow Interrupt (PIE) */
	SET_BIT(TIMSK,0);
	#elif TIMER0_OV_INTERRUPT==DISABLE 
	/*Disable OVER Flow Interrupt (PIE) */
	CLR_BIT(TIMSK,0);
    #else
#warning ("Warning")

	#endif

	#elif TIMER0_MODE==CTC_MODE
	/*Select Mode (CTC)*/
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	
	#if TIMER0_COMPARE_MODE==Normal_Port
	/*Select Compare Out Put Mode(Normal)*/
	CLR_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
	
	#elif TIMER0_COMPARE_MODE==Toggle_OC0
	SET_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
	
	#elif TIMER0_COMPARE_MODE==Clear_OC0
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5); 
	
	#elif TIMER0_COMPARE_MODE==SET_OC0
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
    #endif
	
	#if TIMER0_CTC_INTERRUPT==ENABLE 
	/*Enable CTC Interrupt (PIE) */
	SET_BIT(TIMSK,1);
	
	#elif TIMER0_CTC_INTERRUPT==DISABLE
	/*Disable CTC Interrupt (PIE) */
	CLR_BIT(TIMSK,1);
	
	#endif
	#elif TIMER0_MODE==PWM_MODE
		/*Select Mode(PWM) */
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	/*Select Non Inverting Mode*/
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);
	#else
		#warning ("Wrong Config For Mode")
	#endif
	
	#if TIMER0_PRESCALLING==No_Clock_Source
	CLR_BIT(TCCR0,2);
    CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	
	#elif TIMER0_PRESCALLING==No_prescaling
	CLR_BIT(TCCR0,2);
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	
	#elif TIMER0_PRESCALLING==DIV_8
	CLR_BIT(TCCR0,2);
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	
	#elif TIMER0_PRESCALLING==DIV_64
	CLR_BIT(TCCR0,2);
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	
	#elif TIMER0_PRESCALLING==DIV_256
	SET_BIT(TCCR0,2);
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	
	#elif TIMER0_PRESCALLING==DIV_1024
	SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	
	#elif TIMER0_PRESCALLING==Rising_Edge
	SET_BIT(TCCR0,0);
    SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	
	#elif TIMER0_PRESCALLING==Falling_Edge
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	
	#else 
		#warning("Wrong Config For Prescaler")
	#endif

	
	
	
}

void TIM0_PrelaodValue(u8 Copy_U8PV0)
{
	
	/*Preload Value*/
	TCNT0=Copy_U8PV0 ;
	
}


void TIM0_CompareValue(u8 Copy_U8CV0)
{
	/*Set Compare Value*/
	OCR0=Copy_U8CV0;
}


void TIM0_FastPWM_Set_DutyCycle(u8 Copy_U8DC)
{
	/*Set Duty Cycle*/
	OCR0=Copy_U8DC;
}

void TIM1_Init_OV(void)
{
	/*Select Normal Mode*/
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	
	/*Select Prescaler (256)*/
	SET_BIT(TCCR1B,2);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);
	
	/*Enable OVER Flow Interrupt (PIE) */
	SET_BIT(TIMSK,2);
	
	/*Enable ICU Interrupt (PIE)*/
	SET_BIT(TIMSK,5);
	
}

#if TIMER0_OV_INTERRUPT==ENABLE 
void TIM0_Fun(void (*ptf)(void))
{
	TIM0_CB=ptf;
}

void __vector_11(void) /*TIM0_Over Flow Int*/
{
	TIM0_CB();
//	static u8 OV_Count=0;
//	OV_Count++;
//	if(OV_Count==123)
//	{
//		TCNT0=238;
//		MDIO_VoidTogglePin(PORTB,7);
//		OV_Count=0;
//
//	}
//
//
}
#endif

void __vector_9(void) /*TIM1_Over Flow Int*/
{
	
	OV_Count1++;
}

void __vector_6(void) /*TIM_ICU Int*/
{
	if(Flag==0)
	{
		/*Capture First Change*/
		Snap1=ICR1;
		
		/*Select Sense Control(ICES) :Falling_Edge */
		CLR_BIT(TCCR1B,6); 
		
		Flag=1;
		OV_Count1=0;
		
	}
	
	else if(Flag==1)
	{
		/*Capture Second Change*/
		Snap2=ICR1+(OV_Count1*(2^16));
		
		/*Select Sense Control(ICES) :Rising_Edge */
		SET_BIT(TCCR1B,6); 
		
		Flag=2;
		
		
	}
	
	else if(Flag==2)
	{
		/*Capture 3rd Change*/
		Snap3=ICR1+(OV_Count1*(2^16));
		
		Flag=3;
	}
}

