/*
 * LCD_Program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: abdelrahmanhossam
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

// Include DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"

#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/LCD/LCD_Private.h"
#include "../Include/HAL/LCD/LCD_Cfg.h"

#define F_CPU 8000000UL


void HLCD_voidSendCommand (u8 A_u8Command)
{
	// Send Command --> (RS --> RESET), (RW --> RESET)
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_RESET);
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_RESET);

	// Send Data
	MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Command);

	// Set Pulse on E Pin
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_RESET);
}

void HLCD_voidSendData (u8 A_u8Data)
{
	// Send Command --> (RS --> SET), (RW --> RESET)
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_SET);
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_RESET);

	// Send Data
	MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Data);

	// Set Pulse on E Pin
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_RESET);
}

void HLCD_voidInit(void)
{
	// Wait for more than 30 ms after VDD rises to 4.5V
	_delay_ms(30);

	// Function Set Command
	HLCD_voidSendCommand(FUNCTION_SET);
	// Wait for more than 39 us
	_delay_ms(1);

	// Display ON/OFF Control Command
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	// Wait for more than 39 us
	_delay_ms(1);

	// Display Clear Command
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	// Wait for more than 1.53 ms
	_delay_ms(2);

	// Entry Mode Set Command
	HLCD_voidSendCommand(ENTRY_MODE_SET);
	// Wait for more than 39 us
	_delay_ms(1);
}

void HLCD_voidClearDisplay(void)
{
	// Display Clear Command
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	// Wait for more than 1.53 ms
	_delay_ms(2);
}


void HLCD_voidSendString (u8 *A_u8PtrToString)
{
	while (*A_u8PtrToString > 0)
	{
		HLCD_voidSendData(*A_u8PtrToString++);
	}
}



void HLCD_voidGoToPos (LCD_ROW_e A_LCDRow, LCD_COL_e A_LCDCol)
{
	switch (A_LCDRow)
	{
	case ROW1:
		HLCD_voidSendCommand(ROW1_ADDRESS + A_LCDCol);
		break;

	case ROW2:
		HLCD_voidSendCommand(ROW2_ADDRESS + A_LCDCol);
		break;
	default: break;
	}
}



void HLCD_voidDisplayNumber (u32 A_u32Number)
{

	u32 local_u32Number = 1;
	if (A_u32Number == 0)
	{
		HLCD_voidSendData('0');
	}
	while (A_u32Number != 0)
	{
		local_u32Number = (local_u32Number * 10) + (A_u32Number % 10);
		A_u32Number = A_u32Number / 10;
	}
	while (local_u32Number != 1)
	{
		HLCD_voidSendData(( local_u32Number % 10) + 48);
		local_u32Number = local_u32Number / 10;
	}
}


void HLCD_voidSendSpecialSymbol (u8 *A_pu8CharArr, u8 A_u8PatternNum,LCD_ROW_e A_LCDRow, LCD_COL_e A_LCDCol )
{

}











