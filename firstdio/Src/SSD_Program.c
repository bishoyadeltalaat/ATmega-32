/*
 * SSD_Program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: abdelrahmanhossam
 */


// Include LIB
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

// Include DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"

// Include SSD
#include "../Include/HAL/SSD/SSD_Interface.h"
#include "../Include/HAL/SSD/SSD_Private.h"
#include "../Include/HAL/SSD/SSD_Cfg.h"


void HSSD_voidDisplayNumber(DIO_PORT_e A_DIOPort,u8 A_u8NumberValue)
{
	// Input Validation
	if ( A_DIOPort <= DIO_PORTD )
	{
		switch (A_DIOPort)
		{
		case DIO_PORTA:
			MDIO_voidSetPortValue(DIO_PORTA,A_u8NumberValue);
			break;
		case DIO_PORTB:
			MDIO_voidSetPortValue(DIO_PORTB,A_u8NumberValue);
			break;
		case DIO_PORTC:
			MDIO_voidSetPortValue(DIO_PORTC,A_u8NumberValue);
			break;
		case DIO_PORTD:
			MDIO_voidSetPortValue(DIO_PORTD,A_u8NumberValue);
			break;
		}
	}
	else
	{
		// Do Nothing
	}


}
HSSD_voidDisplayNumbersAscending(DIO_PORT_e A_DIOPort, u16 A_u16TimetoWait)
{
	u8 SSD_u8ArrOfNumbers [10]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE} ;
	u8 i;
	// Input Validation
	if ( A_DIOPort <= DIO_PORTD )
	{
		switch (A_DIOPort)
		{
		case DIO_PORTA:
			for(i=0;i<=10;i++){
				HSSD_voidDisplayNumber(DIO_PORTA,SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);
			}
			break;
		case DIO_PORTB:
			for(i=0;i<=10;i++){
				HSSD_voidDisplayNumber(DIO_PORTB,SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);
			}
			break;
		case DIO_PORTC:
			for(i=0;i<=10;i++){
				HSSD_voidDisplayNumber(DIO_PORTC,SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);
			}
			break;
		case DIO_PORTD:
			for(i=0;i<=10;i++){
				HSSD_voidDisplayNumber(DIO_PORTD,SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);
			}
			break;
		}
	}
	else
	{
		// Do Nothing
	}









}

















