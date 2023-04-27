/*                      ************************************************************************
 						**               Created on: Sep 10, 2021                             **
                        **                Author: Abdallah Taha                               **           
						**                File Name : HLCD_Interface                          **
						**                 V 1.0                                              **
						**         Description:Declration For All Function Of LCD             **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						************************************************************************/


#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H


void HLCD_VoidSendChar(u8 Copy_U8Data);
void HLCD_VoidSendCommand(u8 Copy_U8Command);
void HLCD_VoidInit(void);
void HLCD_VoidInit4Bit(void);
void HLCD_VoidSendString(u8 *Coby_U8String);
void HLCD_VoidSetPostion(u8 Copy_U8Row,u8 Copy_U8Colm);
void HLCD_VoidSendNumber(u32 Copy_U8Number);
void HLCD_VoidDrawChar(void);



#endif