/*
 * LCD_program.c
 *
 *  Created on: Sep 9, 2022
 *      Author: abdelrahmanhossam
 */
#include <util/delay.h>

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_interface.h"

#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/LCD/LCD_private.h"
#include "../include/HAL/LCD/LCD_configuration.h"

#define F_CPU 8000000UL

void HLCD_voidSendData (u8 A_u8Data)
{
	// RS ----> 1 , RW ----> 0
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_HIGH);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);
	// Send Data to LCD
	MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Data);
	// Set Pulse on E pin with 2 ms delay
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_LOW);
}
void HLCD_voidSendCommand (u8 A_u8Command)
{
	// RS ----> 0 , RW ----> 0
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_LOW);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);
	// Send Data to LCD
	MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Command);
	// Set Pulse on E pin with 2 ms delay
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_LOW);
}


void HLCD_voidInit (void)
{
	// Wait for more than 30ms after VDD rises to 4.5V.
	_delay_ms(30);
	// Function Set
	HLCD_voidSendCommand(FUNCTION_SET);
	// Wait for more than 39 us
	_delay_us(40);
	// Display ON/OFF Control
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	// Wait for more than 39 us
	_delay_us(40);
	// Display Clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	// Wait for more than 1.53 ms
	_delay_ms(2);
	// Entry Mode Set
	HLCD_voidSendCommand(ENTRY_MODE_SET);
}

void HLCD_voidClearDisplay(void)
{
	// Display Clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	// Wait for more than 1.53 ms
	_delay_ms(2);
}

void HLCD_voidSentString (u8 *A_Pu8String)
{
	while (*A_Pu8String>0)
	{
		HLCD_voidSendData(*A_Pu8String++);
	}
}


void HLCD_voidGoToPos(u8 A_u8RowNum, u8 A_u8ColNum)
{
    switch (A_u8RowNum)
    {
    case LCD_ROW_ONE:
        HLCD_voidSendCommand(LCD_ROW1_ADDRESS + A_u8ColNum);
        break;
    case LCD_ROW_TWO:
        HLCD_voidSendCommand(LCD_ROW2_ADDRESS + A_u8ColNum);
        break;
    default:
        break;
    }
    _delay_ms(1);
}

HLCD_voidDisplayNumber(u32 A_u32Number)
{
    u32 local_u32Number = 1;
    if (A_u32Number == 0)
    {
        HLCD_voidSendData('0');
    }
    while (A_u32Number != 0)
    {
        local_u32Number = ((local_u32Number * 10) + (A_u32Number % 10));
        A_u32Number = A_u32Number / 10;
    }
    while (local_u32Number != 1)
    {
        HLCD_voidSendData((local_u32Number % 10) + 48);
        local_u32Number = local_u32Number / 10;
    }
}


void LCD_voidSendSpecialCharacter(u8 *A_pu8CharArr, u8 A_u8PatternNum,u8 A_u8LineNum, u8 A_ColNum)
{
	u8 local_u8CGRAMAddress, local_u8Counter;
	/* Calculate CGRAM Address = Pattern Number * 8 */
	local_u8CGRAMAddress = A_u8PatternNum * 8;
	SET_BIT(local_u8CGRAMAddress, 6);
	/* Send Command to set CGRAM Address */
	HLCD_voidSendCommand(local_u8CGRAMAddress);

	for (local_u8Counter = 0; local_u8Counter < 8; local_u8Counter++)
	{
		/* Send byte from character array */
		HLCD_voidSendData(A_pu8CharArr[local_u8Counter]);
	}

	/* Send Command to set DDRAM Address */
	HLCD_voidGoToPos(A_u8LineNum, A_ColNum);
	/* Display pattern from CGRAM */
	HLCD_voidSendData(A_u8PatternNum);
}
