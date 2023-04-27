                       /************************************************************************
 						**               Created on: Dec 5, 2021                              **
                        **                Author: Abdallah Taha                               **           
						**                File Name : MTIMER_CONFIG                           **
						**                 V 1.1                                              **
						**         Description:Timer 0 Configruation                          **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						************************************************************************/

#ifndef MTIMER_PRIVATE_H
#define MTIMER_PRIVATE_H

/*Registers Define*/
#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define OCR0  *((volatile u8*)0x5C)
#define TIMSK *((volatile u8*)0x59)
#define TIFR  *((volatile u8*)0x58)
#define SFIOR *((volatile u8*)0x50)
#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)
#define ICR1 *((volatile u16*)0x46)
#define OCR1A *((volatile u16*)0x4A)
#define OCR1B *((volatile u16)*0x48)
#define TCNT1 *((volatile u16)*0x4C)
#define TCNT1 *((volatile u16)*0x4C)


/*Modes Of Timer 0*/
#define NORMAL_MODE 0  
#define CTC_MODE    1
#define PWM_MODE    2


/*Types Of prescaling*/
#define No_Clock_Source 0
#define No_prescaling 1
#define DIV_8  2 
#define DIV_64 3 
#define DIV_256 4
#define Falling_Edge 6
#define Rising_Edge 7

/*Compare Modes*/
#define Normal_Port 1
#define Toggle_OC0 2
#define Clear_OC0 3
#define Set_OC0 4

#define DISABLE  0  
#define ENABLE   1 




/*ISR Declration*/
void __vector_11(void) __attribute__((signal));
void __vector_9(void) __attribute__((signal));
void __vector_6(void) __attribute__((signal));

#endif
