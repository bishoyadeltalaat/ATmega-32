/*
 * LCD_Interface.h
 *
 *  Created on: Sep 15, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

typedef enum{
	ROW1=1,
	ROW2
}LCD_ROW_e;

typedef enum{
	LCD_COL1=1,
	LCD_COL2,
	LCD_COL3,
	LCD_COL4,
	LCD_COL5,
	LCD_COL6,
	LCD_COL7,
	LCD_COL8,
	LCD_COL9,
	LCD_COL10,
	LCD_COL11,
	LCD_COL12,
	LCD_COL13,
	LCD_COL14,
	LCD_COL15,
	LCD_COL16
}LCD_COL_e;

void HLCD_voidSendCommand (u8 A_u8Command);
void HLCD_voidSendData (u8 A_u8Data);
void HLCD_voidClearDisplay(void);
void HLCD_voidInit(void);
void HLCD_voidGoToPos (LCD_ROW_e A_LCDRow, LCD_COL_e A_LCDCol);
void HLCD_voidSendString (u8 *A_u8PtrToString);
void HLCD_voidDisplayNumber (u32 A_u32Number);
#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
