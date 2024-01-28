/*
 * App.c
 *
 *  Created on: Sep 9, 2023
 *      Author: abdelrahmanhossam
 */

#include <avr/io.h>
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/SSD/SSD_Interface.h"
#define F_CPU 8000000UL


/*int main()
{

MDIO_voidInit();
MDIO_voidSetPortDirection(DIO_PORTD,255);
u8 i;
	while(1)
	{
		u8 SSD_u8ArrOfNumbers [10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,EIGHT,NINE};

		for(i=0;i<=10;i++){
HSSD_voidDisplayNumber(DIO_PORTD,SSD_u8ArrOfNumbers[i]);
_delay_ms(2000);
		}
	}
}

 */
int main()
{

	MDIO_voidInit();

	MDIO_voidSetPortDirection(DIO_PORTD,255);
	while(1)
	{
		HSSD_voidDisplayNumbersAscending(DIO_PORTD,000);
	}
}

