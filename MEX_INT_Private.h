/*                      ************************************************************************
 						**               Created on: Oct 9, 2021                             **
                        **                Author: Abdallah Taha                               **           
						**                File Name : MEX_INT_Private                         **
						**                 V 1.0                                              **
						**         Description: Definetion Of All Registers Of Extrenal INT   **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						************************************************************************/







#ifndef MEX_INT_PRIVATE_H
#define MEX_INT_PRIVATE_H


#define MCUCR *((u8*)0x55)
#define MCUCSR *((u8*)0x54)
#define GICR *((u8*)0x5B)
#define GIFR *((u8*)0x5A)

void __vector_1(void) __attribute__((signal));

void __vector_2(void) __attribute__((signal));





#endif
