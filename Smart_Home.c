/*
 * Smart_Home.c
 *
 *  Created on: Nov 17, 2021
 *      Author: Abdallah Taha
 */
#include "STD_TYPES.h"
#include "MDIO_INTERFACE.h"
#include "HLCD_Interface.h"
#include "MURT_Interface.h"
#include "MGIE_Interface.h"
#include "MTimer_Interface.h"
#include "MADC_Interface.h"
#include "Smart_Home_Private.h"
#include <avr/delay.h>
u8 Login_Trial=False;
u8 Door_State=Closed;
u8 Login_state=OUT;
u8 Data=0;
int main(void)
{
	/*Super Loop*/
	while(1)
	{
		/*Login */
	while(!Login_Trial)
	{
MDIO_VoidSetPinDirection(PORTA,PIN7,OUTPUT);
MDIO_VoidSetPinValue(PORTA,PIN7,HIGH);

/*Password & ID */
	u8 *IDTrue[3]={0};
	u8 *PassTrue[3]={0};
/*Initialize Peripherals*/
ADC_Init();
URT_Init();
HLCD_VoidInit();
/*TIM0 Init*/
TIM0_Init();
u8 ID=0;
u8 Pass=0;

/*Password Check Function*/
void Pass_Check(void)
{
	Pass=0;

	HLCD_VoidSendCommand(0x01);
	HLCD_VoidSetPostion(0,0);
	HLCD_VoidSendString("Password:");
	for(u8 i=0;i<=3;i++)
	{
		/*Get Password From User*/
		Pass=URT_Recevier();
        URT_Transmitte(PassTrue[i]);
        /*Display Password On LCD*/
        HLCD_VoidSendChar('*');
        /*Store Password In Array*/
        PassTrue[i]=Pass;
	}
}

/*ID Check Function*/
void ID_CHECK(void)
{
	ID=0;
	HLCD_VoidSendCommand(0x01);
	HLCD_VoidSetPostion(0,0);
	HLCD_VoidSendString("ID:");
	for(u8 i=0;i<=3;i++)
	{
		/*Get ID From User*/
		ID=URT_Recevier();
        URT_Transmitte(IDTrue[i]);
        /*Display ID On LCD*/
        HLCD_VoidSendChar(ID);
        /*Store ID In Array*/
        IDTrue[i]=ID;
	}
}
/*Go To ID Check Function*/
ID_CHECK();
u8 y=0;
u8 Pas=0;
for(y=0;y<3;y++)
{
		/*If Correct ID*/
	if(IDTrue[0]=='A'&&IDTrue[1]=='b'&&IDTrue[2]=='d'&&IDTrue[3]=='o')
	{
		y=4; //For Exit For Loop
		HLCD_VoidSendCommand(0x01);
		HLCD_VoidSetPostion(0,0);
		/*Go To Pass Check Function*/
		Pass_Check();

		for(Pas=0;Pas<3;Pas++)
		{
				/*If Correct Password*/
			if(PassTrue[0]=='1'&&PassTrue[1]=='0'&&PassTrue[2]=='0'&&PassTrue[3]=='0')
			{
				Login_Trial=True;
				Pas=4; //For Exit For Loop
				HLCD_VoidSendCommand(0x01);
				HLCD_VoidSetPostion(0,4);
				HLCD_VoidSendString("Hello Abdo");
				Login_state=IN;
			}

				/*If Incorrect Password*/
				else if(Pas<3)
				{
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSendString("Wrong Pass Try Again");
					_delay_ms(1000);
					/*Go To Pass Check Function*/
					Pass_Check();
				}
				/*If Incorrect Password*/
				else if(Pas==3)
				{
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSendString("Wrong Pass ");
					_delay_ms(1000);
					MDIO_VoidSetPinValue(PORTA,PIN7,LOW);
					HLCD_VoidSendCommand(0x01);
				}
		}
	}
	else if(IDTrue[0]=='S'&&IDTrue[1]=='n'&&IDTrue[2]=='t'&&IDTrue[3]=='a')
		{
			y=4; //For Exit For Loop
			HLCD_VoidSendCommand(0x01);
			HLCD_VoidSetPostion(0,0);
			/*Go To Pass Check Function*/
			Pass_Check();

			for(Pas=0;Pas<3;Pas++)
			{
					/*If Correct Password*/
				if(PassTrue[0]=='1'&&PassTrue[1]=='2'&&PassTrue[2]=='0'&&PassTrue[3]=='0')
				{
					Login_Trial=True;
					Pas=4; //For Exit For Loop
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,4);
					HLCD_VoidSendString("Hello Santos");
					Login_state=IN;
				}


					/*If Incorrect Password*/
					else if(Pas<3)
					{
						HLCD_VoidSendCommand(0x01);
						HLCD_VoidSendString("Wrong Pass Try Again");
						_delay_ms(1000);
						/*Go To Pass Check Function*/
						Pass_Check();
					}
					/*If Incorrect Password*/
					else if(Pas==3)
					{
						HLCD_VoidSendCommand(0x01);
						HLCD_VoidSendString("Wrong Pass ");
						_delay_ms(1000);
						MDIO_VoidSetPinValue(PORTA,PIN7,LOW);
						HLCD_VoidSendCommand(0x01);
					}
			}
		}
	else if(IDTrue[0]=='O'&&IDTrue[1]=='m'&&IDTrue[2]=='a'&&IDTrue[3]=='r')
		{
			y=4; //For Exit For Loop
			HLCD_VoidSendCommand(0x01);
			HLCD_VoidSetPostion(0,0);
			/*Go To Pass Check Function*/
			Pass_Check();

			for(Pas=0;Pas<3;Pas++)
			{
					/*If Correct Password*/
				if(PassTrue[0]=='1'&&PassTrue[1]=='1'&&PassTrue[2]=='0'&&PassTrue[3]=='0')
				{
					Login_Trial=True;
					Pas=4; //For Exit For Loop
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,4);
					HLCD_VoidSendString("Hello Omar");
					Login_state=IN;
				}


					/*If Incorrect Password*/
					else if(Pas<3)
					{
						HLCD_VoidSendCommand(0x01);
						HLCD_VoidSendString("Wrong Pass Try Again");
						_delay_ms(1000);
						/*Go To Pass Check Function*/
						Pass_Check();
					}
					/*If Incorrect Password*/
					else if(Pas==3)
					{
						HLCD_VoidSendCommand(0x01);
						HLCD_VoidSendString("Wrong Pass ");
						_delay_ms(1000);
						MDIO_VoidSetPinValue(PORTA,PIN7,LOW);
						HLCD_VoidSendCommand(0x01);
					}
			}
		}

/*If Incorrect ID*/
else if(y<3)
{


	HLCD_VoidSendCommand(0x01);
	HLCD_VoidSendString("Wrong ID Try Again");
	_delay_ms(1000);
	/*Go To ID Check Function*/
	ID_CHECK();

}
/*If Incorrect ID*/
if(y==2)
{
	Login_Trial=True;
	HLCD_VoidSendCommand(0x01);
		HLCD_VoidSendString("Wrong ID ");
		_delay_ms(1000);
		/*Turn Off LCD */
		MDIO_VoidSetPinValue(PORTA,PIN7,LOW);
		HLCD_VoidSendCommand(0x01);

}
}
	}

	/*While ID & Password Correct*/
while(Login_state)
{
	/*Display Options On LCD*/

	_delay_ms(2000);
	HLCD_VoidSendCommand(0x01);
	HLCD_VoidSetPostion(0,0);
	HLCD_VoidSendString("a:O/D");
	HLCD_VoidSetPostion(0,7);
	HLCD_VoidSendString("b:C/D");
	HLCD_VoidSetPostion(1,0);
	HLCD_VoidSendString("c:Temp");
	HLCD_VoidSetPostion(1,9);
	HLCD_VoidSendString("<<");



	Data=URT_Recevier();
	if(Data=='a')
	{
		if(Door_State==Closed)
		{
			MDIO_VoidSetPinDirection(PORTB,3,OUTPUT);
		HLCD_VoidSendCommand(0x01);
		URT_SendString("Open Door");
		HLCD_VoidSetPostion(0,0);
		HLCD_VoidSendString("Open Door");
		TIM0_FastPWM_Set_DutyCycle(13);
		Door_State=Open;

		}
		else if(Door_State==Open)
		{
			HLCD_VoidSendCommand(0x01);
						HLCD_VoidSetPostion(0,0);
						HLCD_VoidSendString("Door Already Open");
		}

	}

	else if(Data=='b')
	{
		if(Door_State==Open)
		{
			MDIO_VoidSetPinDirection(PORTB,3,OUTPUT);
		HLCD_VoidSendCommand(0x01);
		URT_SendString("Close Door");
		HLCD_VoidSetPostion(0,0);
		HLCD_VoidSendString("Close Door");
		TIM0_FastPWM_Set_DutyCycle(75);
		Door_State=Closed;



		}
		else if(Door_State==Closed)
		{
			HLCD_VoidSendCommand(0x01);
			HLCD_VoidSetPostion(0,0);
			HLCD_VoidSendString("Door Already Closed");
		}


	}
	else if(Data=='c')
	{
		static u16 Temp=0;
		static u16 Digital_ADC=0;

		HLCD_VoidSendCommand(0x01);
				Digital_ADC=ADC_ReadData(ADC_CH_LM);
				Temp=(Digital_ADC*5000ul)/1024;
				Temp/=10;
				HLCD_VoidSetPostion(0,0);
				HLCD_VoidSendString("Temp:");
				HLCD_VoidSendNumber(Temp);
				HLCD_VoidSendString("C");
				_delay_ms(4000);

	}

	else if(Data=='<')
	{
		Login_state=OUT;
		Login_Trial=False;
	}

} //End Program

} //End Super Loop
	return 0;
} //End Main
