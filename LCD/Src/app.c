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
#include "../Include/HAL/LCD/LCD_Interface.h"
#define F_CPU 8000000UL



int main ()
{
	MDIO_voidInit();
	HLCD_voidInit();

	u8 local_u8KeypadValue ;
	u8 local_u8CharCounter=0;
	while(1)
	{
		local_u8KeypadValue = HKEYPAD_u8GetPressedKey();
		if (local_u8KeypadValue != 255)
		{
			HLCD_voidSendData(local_u8KeypadValue);
			local_u8CharCounter++;
			if (local_u8CharCounter==16)
			{
				HLCD_voidGoToPos(LCD_ROW2, LCD_COL1);
			}
			else if (local_u8CharCounter==32)
			{
				HLCD_voidClearDisplay();
				HLCD_voidGoToPos(LCD_ROW1, LCD_COL1);
				local_u8CharCounter = 0;
			}
		}
	}
}















