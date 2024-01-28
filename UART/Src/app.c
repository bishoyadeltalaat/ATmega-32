/*
 * app.c
 *
 *  Created on: Sep 1, 2023
 *      Author: abdelrahmanhossam
 */


#include <util/delay.h>
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/GI/GI_interface.h"
#include "../Include/MCAL/UART/UART_Interface.h"
#include "../Include/HAL/LED/LED_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"


#define F_CPU 8000000UL

int main ()
{
	MDIO_voidInit();
	MUART_voidInit();

	u8 local_u8ReceivedData=255;

	MUART_voidSendStringSyncNonBlocking("To Turn ON the LED Press o or O\r\nTo Turn OFF the LED Press f or F\r\n");
	while(1)
	{
		local_u8ReceivedData = MUART_u8ReadByteSyncBlocking();
		if ((local_u8ReceivedData == 'o') || (local_u8ReceivedData == 'O'))
		{
			HLED_voidTurnOn(DIO_PORTA, PIN0);
			MUART_voidSendStringSyncNonBlocking("LED ON\r\n");
		}
		else if ((local_u8ReceivedData == 'f') || (local_u8ReceivedData == 'F'))
		{
			HLED_voidTurnOff(DIO_PORTA, PIN0);
			MUART_voidSendStringSyncNonBlocking("LED OFF\r\n");
		}
	}
}
