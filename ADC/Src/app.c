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
#include "../Include/MCAL/GI/GI_interface.h"
#include "../Include/MCAL/ADC/ADC_Interface.h"
#include "../Include/HAL/LED/LED_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"
#define F_CPU 8000000UL



int main (void)
{
	// PA0 --> I/P Floating , (PC0, PC1, PC2) --> O/P Low
	MDIO_voidInit();
	MADC_voidInit();
	u16 local_u16DigitalValue, local_u16AnalogValue;

	while(1)
	{
		local_u16DigitalValue = MADC_u16GetDigitalvalue(ADC0);
		local_u16AnalogValue  = (local_u16DigitalValue * 5000UL) / 1024; // Read in mv

		if (local_u16AnalogValue < 1500)
		{
			HLED_voidTurnOn (DIO_PORTC, PIN0);
			HLED_voidTurnOff(DIO_PORTC, PIN1);
			HLED_voidTurnOff(DIO_PORTC, PIN2);
		}
		else if (local_u16AnalogValue < 3000)
		{
			HLED_voidTurnOn (DIO_PORTC, PIN0);
			HLED_voidTurnOn (DIO_PORTC, PIN1);
			HLED_voidTurnOff(DIO_PORTC, PIN2);
		}
		else if (local_u16AnalogValue > 3000)
		{
			HLED_voidTurnOn (DIO_PORTC, PIN0);
			HLED_voidTurnOn (DIO_PORTC, PIN1);
			HLED_voidTurnOn (DIO_PORTC, PIN2);
		}
	}
}

/*int main (void)
{
	// PA0 --> I/P Floating , (PC3, PC4, PC5) --> O/P Low, PORT D --> O/P Low
	MDIO_voidInit();
	MADC_voidInit();
	HLCD_voidInit();
	u16 local_u16DigitalValue, local_u16AnalogValue;

	while(1)
	{
		local_u16DigitalValue = MADC_u16GetDigitalvalue(ADC0);
		// Read in mv, then divide by 10 to get Temperature (10mv --> 1 C)
		local_u16AnalogValue  = (local_u16DigitalValue * 500UL) / 1024;
		HLCD_voidClearDisplay();
		HLCD_voidDisplayString("Temperature: ");
		HLCD_voidDisplayNumber(local_u16AnalogValue);
		_delay_ms(5000);

	}
}*/
