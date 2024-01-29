/*
 * STEPPER_Program.c
 *
 *  Created on: Nov 5, 2023
 *      Author: D E L L
 */

// Include LIB
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

// Include DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Cfg.h"

// Include STEPPER
#include "../Include/HAL/STEPPER/STEPPER_Interface.h"
#include "../Include/HAL/STEPPER/STEPPER_Private.h"
#include "../Include/HAL/STEPPER/STEPPER_Cfg.h"

//#include "DIO_P"
void HSTEPPER_voidInit(void)
{
	MDIO_voidSetPinDirection(STEPPER_PORT, BLUE, PIN_OUTPUT);
	MDIO_voidSetPinDirection(STEPPER_PORT, PINK, PIN_OUTPUT);
	MDIO_voidSetPinDirection(STEPPER_PORT, YELLOW, PIN_OUTPUT);
	MDIO_voidSetPinDirection(STEPPER_PORT, ORANGE, PIN_OUTPUT);

	MDIO_voidSetPinValue(STEPPER_PORT, BLUE, PIN_SET);
	MDIO_voidSetPinValue(STEPPER_PORT, PINK, PIN_SET);
	MDIO_voidSetPinValue(STEPPER_PORT, YELLOW, PIN_SET);
	MDIO_voidSetPinValue(STEPPER_PORT, ORANGE, PIN_SET);
}

void HSTEPPER_voidRotate(u16 A_u16Angle)
{
	MDIO_voidSetPinValue(STEPPER_PORT, BLUE, PIN_SET);
	MDIO_voidSetPinValue(STEPPER_PORT, PINK, PIN_SET);
	MDIO_voidSetPinValue(STEPPER_PORT, YELLOW, PIN_SET);
	MDIO_voidSetPinValue(STEPPER_PORT, ORANGE, PIN_SET);

	u16 max = (10*A_u16Angle/7); // TURNS
	u16 i=0;

	for(i=0;i<max;i++){
		MDIO_voidSetPinValue(STEPPER_PORT, BLUE, PIN_RESET);
		MDIO_voidSetPinValue(STEPPER_PORT, PINK, PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT, YELLOW, PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT, ORANGE, PIN_SET);
		_delay_ms(2);

		MDIO_voidSetPinValue(STEPPER_PORT,BLUE,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,PINK,PIN_RESET);
		MDIO_voidSetPinValue(STEPPER_PORT,YELLOW,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,ORANGE,PIN_SET);
		_delay_ms(2);

		MDIO_voidSetPinValue(STEPPER_PORT,BLUE,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,PINK,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,YELLOW,PIN_RESET);
		MDIO_voidSetPinValue(STEPPER_PORT,ORANGE,PIN_SET);
		_delay_ms(2);

		MDIO_voidSetPinValue(STEPPER_PORT,BLUE,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,PINK,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,YELLOW,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,ORANGE,PIN_RESET);
		_delay_ms(2);
	}
}
void HSTEPPER_voidCounterRotate(u16 A_u16Angle)
{
	MDIO_voidSetPinValue(STEPPER_PORT,BLUE,PIN_SET);
	MDIO_voidSetPinValue(STEPPER_PORT,PINK,PIN_SET);
	MDIO_voidSetPinValue(STEPPER_PORT,YELLOW,PIN_SET);
	MDIO_voidSetPinValue(STEPPER_PORT,ORANGE,PIN_SET);

	u16 max = (10*A_u16Angle/7); // TURNS
	u16 i=0;

	for(i=0;i<max;i++){
		MDIO_voidSetPinValue(STEPPER_PORT,BLUE,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,PINK,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,YELLOW,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,ORANGE,PIN_RESET);
		_delay_ms(2);

		MDIO_voidSetPinValue(STEPPER_PORT,BLUE,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,PINK,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,YELLOW,PIN_RESET);
		MDIO_voidSetPinValue(STEPPER_PORT,ORANGE,PIN_SET);
		_delay_ms(2);

		MDIO_voidSetPinValue(STEPPER_PORT,BLUE,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,PINK,PIN_RESET);
		MDIO_voidSetPinValue(STEPPER_PORT,YELLOW,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,ORANGE,PIN_SET);
		_delay_ms(2);

		MDIO_voidSetPinValue(STEPPER_PORT,BLUE,PIN_RESET);
		MDIO_voidSetPinValue(STEPPER_PORT,PINK,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,YELLOW,PIN_SET);
		MDIO_voidSetPinValue(STEPPER_PORT,ORANGE,PIN_SET);
		_delay_ms(2);
	}
}




