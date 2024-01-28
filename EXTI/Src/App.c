/*
 * App.c
 *
 *  Created on: Sep 9, 2023
 *      Author: abdelrahmanhossam
 */


#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/EXTI/EXTI_Interface.h"
#include "../Include/MCAL/GI/GI_interface.h"
#include "../Include/HAL/LED/LED_Interface.h"
#define F_CPU 8000000UL

void FUNC(void)
{
	HLED_voidToggleLED(DIO_PORTA, PIN0);
}

int main()
{
	MDIO_voidInit();
	MEXTI_voidConfig(EXTI0, FALLING_EDGE);
	MEXTI_voidSetCallBack(EXTI0,FUNC);
	MEXTI_voidEnable(EXTI0);
	MGI_voidEnable();
	while(1)
	{

	}
}
