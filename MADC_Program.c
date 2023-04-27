/*    Created on: Oct 18, 2021
 *      Author: Abdallah Taha */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MADC_Private.h"


void ADC_Init(void)
{
	/*Enable ADC*/
	SET_BIT(ADCSRA,7);
	
	/*Select VRef*/
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	
	/*Disable Auto Trigger*/
	CLR_BIT(ADCSRA,5);
	
	/*Disable Interrupt*/
	CLR_BIT(ADCSRA,3);
	
	/*ADLR (Right Adjustment)*/
	CLR_BIT(ADMUX,5);
	
	/*Configure Prescaler (/128)*/
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
	
	
}

u16 ADC_ReadData(u8 Copy_U8Channel_Number)
{
	/*Channel Selection*/
	ADMUX&=0b11100000;
	ADMUX|=Copy_U8Channel_Number;
	
	/*Start Single Conversion*/
	SET_BIT(ADCSRA,6);
	
	/*Waiting For Interrupt Flag When Conversion End*/
	while(GET_BIT(ADCSRA,4)==0);
	
	/*Clear Interrupt Flag*/
	SET_BIT(ADCSRA,4);
	
	/*Read Data From ADC Data Reg*/
	
	
	/*u8 LOW_Value=ADCL;
	u16 LOC_Digital_ADC =ADCH;
	
	LOC_Digital_ADC=(LOC_Digital_ADC<<8)|LOW_Value;
	
	return LOC_Digital_ADC;*/
	
	
	return ADCData ;
	
	

	
	
	
}