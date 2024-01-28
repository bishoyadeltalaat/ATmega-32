/*
 * LCD_configuration.h
 *
 *  Created on: Sep 9, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_
#define INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_

#define LCD_DATA_PORT    DIO_PORTA
#define LCD_CONTROL_PORT DIO_PORTB

#define LCD_RS_PIN	PIN0
#define LCD_RW_PIN	PIN1
#define LCD_E_PIN	PIN2

// 0 --> 1 Line
// 1 --> 2 Lines
#define NO_OF_LINES 1

// 0 --> 5*7
// 1 --> 5*10
#define CHARACTER_FONT 0

// 0 ---> Display Off
// 1 ---> Display On
#define DISPLAY_ON  1


// 0 ---> Cursor Not Displayed
// 1 ---> Cursor is  Displayed
#define CURSOR_DISPLAY 1

// 0 ---> Cursor doesn't blink
// 1 ---> Cursor blinks
#define CURSOR_BLINK   1

// 0 ---> Display Data from Right to Left
// 1 ---> Display Data from Left  to Right
#define DATA_DIRECTION 1
#endif /* INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_ */
