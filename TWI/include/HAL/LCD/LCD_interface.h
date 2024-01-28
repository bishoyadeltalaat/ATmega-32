/*
 * LCD_interface.h
 *
 *  Created on: Sep 9, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

#define LCD_ROW_ONE 1
#define LCD_ROW_TWO 2

void HLCD_voidSendData (u8 A_u8Data);

void HLCD_voidSendCommand (u8 A_u8Command);

void HLCD_voidInit (void);

void HLCD_voidClearDisplay(void);

void HLCD_voidSentString (u8 *A_Pu8String);

HLCD_voidDisplayNumber(u32 A_u32Number);

void HLCD_voidGoToPos(u8 A_u8RowNum, u8 A_u8ColNum);

void LCD_voidSendSpecialCharacter(u8 *A_pu8CharArr, u8 A_u8PatternNum,u8 A_u8LineNum, u8 A_ColNum);
#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
