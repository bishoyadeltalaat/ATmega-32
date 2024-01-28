
#include <util/delay.h>

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/MCAL/TWI/TWI_interface.h"

#include "../Include/HAL/LED/LED_interface.h"
#include "../Include/HAL/EEPROM/EEPROM_interface.h"
#define F_CPU 8000000UL



void main(void)
{
	// local variable to return data in
	u8 local_u8Data=0;

	// Initialize DIO --> PORTD LCD Data, PORTB LCD Control, PORTC TWI
	MDIO_voidInit();
	// Initialize LCD
	HLCD_voidInit();

	// Initialize TWI in Master Mode
	TWI_voidInitMaster(0);


	// Send byte to EEPROM
	EEPROM_voidSendDataByte(5, 7);

	// Read Byte from EEPROM
	local_u8Data= EEPROM_u8ReadDataByte(5);

	// Display Results
//	HLCD_voidSendString("Expected Value: ");
//	HLCD_voidDisplayNumber(7);
//	HLCD_voidGoToPos(2, 1);
//	HLCD_voidSendString("Returned Value: ");
//	HLCD_voidDisplayNumber(local_u8Data);
	if (local_u8Data == 7)
	{
		       MDIO_voidSetPinDirection(DIO_PORTA,PIN0,DIO_HIGH);
				MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_HIGH);

	}
	// Super Loop
	while (1);

}
