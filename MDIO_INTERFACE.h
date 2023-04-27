/*                      ************************************************************************
 						**               Created on: Aug 20, 2021                             **
                        **                Author: Abdallah Taha                               **           
						**                File Name : MDIO_Interface                          **
						**                 V 1.0                                              **
						**         Description:Declration For All Function Of DIO             **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						************************************************************************/


#ifndef MDIO_INTERFACE_H
#define MDIO_INTERFACE_H

#include "MDIO_Private.h"

void MDIO_VoidSetPinDirection(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Direction);
u8 MDIO_u8GetPinValue(u8 Copy_U8Port ,u8 Copy_U8Pin );
void MDIO_VoidSetPinValue(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Value);
void MDIO_VoidSetPortDirection(u8 Copy_U8Port ,u8 Copy_U8Direction);
void MDIO_VoidSetPortValue(u8 Copy_U8Port ,u8 Copy_U8Value);
void MDIO_VoidTogglePin(u8 Copy_U8Port ,u8 Copy_U8Pin );



#endif
