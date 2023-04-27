#ifndef MTIMER_INTERFACE_H
#define MTIMER_INTERFACE_H
#include "MTimer_Private.h"
void TIM0_Init(void);
void TIM0_PrelaodValue(u8 Copy_U8PV0);
void TIM0_CompareValue(u8 Copy_U8CV0);
void TIM0_FastPWM_Set_DutyCycle(u8 Copy_U8DC);
void TIM0_Fun(void (*ptf)(void));
void TIM1_Init_OV(void);
#endif
