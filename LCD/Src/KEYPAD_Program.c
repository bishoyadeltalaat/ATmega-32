/*
 * KEYPAD_Program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: abdelrahmanhossam
 */




/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

/****************************************************/
/* DIO Directives		     					    */
/****************************************************/
#include "../include/MCAL/DIO/DIO_Interface.h"

/****************************************************/
/* KEYPAD Directives		     					*/
/****************************************************/
#include "../include/HAL/KEYPAD/KEYPAD_interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_private.h"
#include "../include/HAL/KEYPAD/KEYPAD_configuration.h"

#include <util/delay.h>
#define F_CPU 8000000UL

u8 static const global_u8ArrOfRows[KEYPAD_ROW_NO] = KEYPAD_ROWS;
u8 static const global_u8ArrOfCols[KEYPAD_COL_NO] = KEYPAD_COLS;

u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 local_u8KeyValue = NO_KEY_PRESSED;

	u8 local_u8RowCounter=0, local_u8ColCounter=0, local_u8PinValue, local_u8Flag=FLAG_DOWN;

	// Loop on Rows
	for (local_u8RowCounter = 0; local_u8RowCounter< KEYPAD_ROW_NO; local_u8RowCounter++)
	{
		// Activate One Row
		MDIO_voidSetPinValue(KEYPAD_PORT, global_u8ArrOfRows[local_u8RowCounter], KEYPAD_ROW_ACTIVE);

		// Check on COLs
		for (local_u8ColCounter = 0; local_u8ColCounter< KEYPAD_COL_NO; local_u8ColCounter++)
		{
			// Read COL
			local_u8PinValue = MDIO_getPinValue(KEYPAD_PORT, global_u8ArrOfCols[local_u8ColCounter]);
			// Check if key is pressed
			if (local_u8PinValue == KEY_PRESSED)
			{
				// Debouncing Delay
				_delay_ms(KEYPAD_DEBOUNCING_DELAY_ms);
				local_u8PinValue = MDIO_getPinValue(KEYPAD_PORT, global_u8ArrOfCols[local_u8ColCounter]);
				if (local_u8PinValue == KEY_PRESSED)
				{
					while (local_u8PinValue == KEY_PRESSED) // Polling on flag
					{
						local_u8PinValue = MDIO_getPinValue(KEYPAD_PORT, global_u8ArrOfCols[local_u8ColCounter]);
					} // End of while Loop
					local_u8KeyValue = global_u8ArrOfKeyValues[local_u8RowCounter][local_u8ColCounter]; // Get pressed Key Value
					local_u8Flag=FLAG_UP; // Notification for ROWs Loop to break and return
					break;
				}
			}
		} // End of COLs Loop

		// De-Activate One Row
		MDIO_voidSetPinValue(KEYPAD_PORT, global_u8ArrOfRows[local_u8RowCounter], KEYPAD_ROW_DEACTIVATE);

		if (local_u8Flag==FLAG_UP) // check if key was pressed
		{
			break; // break ROWs Loop
		}
	}// End of ROWs Loop

	return local_u8KeyValue; // Return Pressed Key Value
}









