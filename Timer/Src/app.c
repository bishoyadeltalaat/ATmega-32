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
#include "../Include/MCAL/EXTI/EXTI_Interface.h"
#include "../Include/MCAL/GI/GI_interface.h"
#include "../Include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../Include/MCAL/WDT/WDT_Interface.h"
#include "../Include/HAL/LED/LED_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"
#define F_CPU 8000000UL



int main ()
{
	MDIO_voidInit();
	_delay_ms(2000);
	HLED_voidTurnOn(DIO_PORTA, PIN0);
	MWDT_voidEnable(WDT_2_1_s);

	while(1)
	{

	}
}



u16 global_u16PeriodTicks;
u16 global_u16OnTicks;
void ICU_SW (void);
//int main ()
//{
//	/*
//	 * Timer 0 --> Generate PWM on PB3  --> O/P Low			<----
//	 * 															 | Connected Together
//	 * EXTI  0 --> Read the PWM on PD2  --> I/P Floating	<----
//	 * LCD Data Port    --> PORTC       --> O/P Low
//	 * LCD Control Port --> PORTD 3,4,5 --> O/P Low
//	 */
//	MDIO_voidInit();
//	HLCD_voidInit();
//	MEXTI_voidSetCallBack(EXTI0, ICU_SW);
//	MEXTI_voidConfig(EXTI0, RISING_EDGE);
//	MEXTI_voidEnable(EXTI0);
//	MGI_voidEnable();
//	MTIMER0_voidInit();
//	MTIMER1_voidICUSWInit();
//
//	while(1)
//	{
//		while((global_u16PeriodTicks == 0) || (global_u16OnTicks == 0));
//		HLCD_voidGoToPos(ROW1, LCD_COL1);
//		HLCD_voidSendString("--> ");
//		HLCD_voidDisplayNumber(global_u16PeriodTicks);
//		HLCD_voidGoToPos(ROW2, LCD_COL1);
//		HLCD_voidSendString("--> ");
//		HLCD_voidDisplayNumber(global_u16OnTicks);
//	}
//}

void ICU_SW (void)
{
	static u8 local_u8Counter=0;
	local_u8Counter++;
	if (local_u8Counter==1)
	{
		// First Rising Edge
		MTIMER1_voidSetTimer1Value(0);
	}
	else if (local_u8Counter==2)
	{
		// Second Rising Edge
		global_u16PeriodTicks = MTIMER1_u16ReadTimer1Value();
		MEXTI_voidConfig(EXTI0, FALLING_EDGE);
	}
	else if (local_u8Counter==3)
	{
		// First Falling Edge
		global_u16OnTicks = MTIMER1_u16ReadTimer1Value();
		global_u16OnTicks -= global_u16PeriodTicks;
		MEXTI_voidDisable(EXTI0);
		local_u8Counter = 0;
	}
}









// Timer 0 --> 8-bit, Prescaler --> 8, F_CPU --> 8 MHZ, 1 SEC
void Timer0_OVF ()
{
	static u16 counter=0;
	counter++;
	if (counter == 3907)
	{
		MTIMER0_voidSetPreloadValue(192);
		counter=0;
		HLED_voidToggleLED(DIO_PORTC, PIN0);
		HLED_voidToggleLED(DIO_PORTC, PIN1);
		HLED_voidToggleLED(DIO_PORTC, PIN2);
	}

}

void Timer0_CTC ()
{
	static u16 counter=0;
	counter++;
	if (counter == 5000)
	{
		counter=0;
		HLED_voidToggleLED(DIO_PORTC, PIN0);
		HLED_voidToggleLED(DIO_PORTC, PIN1);
		HLED_voidToggleLED(DIO_PORTC, PIN2);
	}

}


// SERVO
//int main()
//{
//	MDIO_voidInit();
//	MTIMER1_voidInit();
//	while(1)
//	{
//
//	}
//}


// Fast PWM
//int main ()
//{
//	// PB3 should be O/P
//	MDIO_voidInit();
//	MTIMER0_voidInit();
//	while(1)
//	{
//		for (u16 i=0; i<255; i+=10)
//		{
//			MTIMER0_voidSetOCR0Value(i);
//			_delay_ms(200);
//		}
//	}
//}



// CTC
//int main()
//{
//	MDIO_voidInit();
//	MTIMER0_voidSetCTCCallback(Timer0_CTC);
//	MTIMER0_voidInit();
//	MGI_voidEnable();
//
//	while (1)
//	{
//
//	}
//
//}



//// OVF
//int main()
//{
//	MDIO_voidInit();
//	MTIMER0_voidSetOVFCallback(Timer0_OVF);
//	MTIMER0_voidInit();
//	MTIMER0_voidSetPreloadValue(192);
//	MGI_voidEnable();
//
//	while (1)
//	{
//
//	}
//
//}
