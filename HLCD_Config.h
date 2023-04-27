/*                      ************************************************************************
 						**               Created on: Sep 25, 2021                             **
                        **                Author: Abdallah Taha                               **           
						**                File Name : HLCD_Config                             **
						**                 V 1.0                                              **
						**           Description: Configration For Lcd                        **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						************************************************************************                                                                    */
						

/* ***************************************     PORTA= 0    ********************************
   ***************************************     PORTB= 1    ********************************
   ***************************************     PORTC= 2    ********************************
   ***************************************     PORTD= 3    ********************************/ 

#ifndef HLCD_CONFIG_H						
#define HLCD_CONFIG_H						


/*Select The Port U Want To Send Data From uC To LCD Through It  */
#define HLCD_DataPort 2 

/*Select The Port That U Connected Rs Pin In It   */
#define HLCD_Rs_Port 1


/*Select The Port That U Connected Rw Pin In It   */
#define HLCD_Rw_Port 1



/*Select The Port That U Connected Enable Pin In It  */
#define HLCD_EN_Port 1


#endif

