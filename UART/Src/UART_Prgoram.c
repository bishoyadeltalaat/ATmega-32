/*
 * UART_Prgoram.c
 *
 *  Created on: May 4, 2023
 *      Author: abdelrahmanhossam
 */


#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/UART/UART_Interface.h"
#include "../include/MCAL/UART/UART_Private.h"
#include "../include/MCAL/UART/UART_Cfg.h"


#define F_CPU 8000000UL
#define NULL 0

static void (*FuncPtr[3]) (void) = {NULL,NULL,NULL};

void MUART_voidInit(void)
{
	u16 local_u16BaudRate = BAUD_RATE_EQUATION;
	// Set Baudrate
	UBRRL = (u8) local_u16BaudRate;
	UBRRH = (u8) (local_u16BaudRate >> 8);

	// Character Size 8-bit
	CLR_BIT(UCSRB,2);

	// Character Size 8-bit
	// Mode Asynchronous operation
	// Parity Disabled
	// 1 Stop Bit
	UCSRC = CONC_BIT(1,0,0,0,0,1,1,0);

	// Enable Receiver
	// Enable Transmitter
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
}


void MUART_voidSendByteSyncBlocking (u8 A_u8DataByte)
{
	// wait until UDR is empty
	while (GET_BIT(UCSRA,5)==0);

	// Set Data into Tx Register and start Transmission
	UDR = A_u8DataByte;

	// wait until UDR is empty
	while (GET_BIT(UCSRA,5)==0);

	// Clear transmit Interrupt flag
	SET_BIT(UCSRA,6);

}

void MUART_voidSendByteSyncNonBlocking (u8 A_u8DataByte)
{
	u32 local_u32Timeout=0;

	// wait until UDR is empty
	while (GET_BIT(UCSRA,5)==0)
	{
		local_u32Timeout++;
		if (local_u32Timeout == NON_BLOCKING_TIME_OUT)
		{
			break;
		}
	}

	if (local_u32Timeout != NON_BLOCKING_TIME_OUT)
	{
		local_u32Timeout = 0;
		// Set Data into Tx Register and start Transmission
		UDR = A_u8DataByte;
		// wait until UDR is empty
		while (GET_BIT(UCSRA,5)==0)
		{
			local_u32Timeout++;
			if (local_u32Timeout == NON_BLOCKING_TIME_OUT)
			{
				break;
			}
		}
		// Clear transmit Interrupt flag
		SET_BIT(UCSRA,6);
	}

}


void MUART_voidSendStringSyncNonBlocking (u8 *A_pu8String)
{
	while(*A_pu8String > 0)
	{
		MUART_voidSendByteSyncNonBlocking(*A_pu8String++);
	}
}


void MUART_voidSendByteAsync (u8 A_u8DataByte)
{
	// Check if Data Register is empty
	if (GET_BIT(UCSRA,5)==1)
	{
		// Send Data
		UDR = A_u8DataByte;
	}
}


u8 MUART_u8ReadByteSyncBlocking (void)
{
	// Wait for Rx Flag
	while(GET_BIT(UCSRA,7)==0);

	return UDR;
}

u8 MUART_u8ReadByteAsync (void)
{
	return UDR;
}

u8 MUART_u8ReadByteSyncNonBlocking (void)
{
	u8 local_u8ReceivedData = NO_VALUE_RETURNED;
	u16 local_u16Timeout = 0;
	// Wait for Rx Flag
	while(GET_BIT(UCSRA,7)==0)
	{
		local_u16Timeout++;
		if (local_u16Timeout == NON_BLOCKING_TIME_OUT)
		{
			break;
		}
	}

	if (local_u16Timeout != NON_BLOCKING_TIME_OUT)
	{
		// Read Received Data from the UDR
		local_u8ReceivedData = UDR;
	}
	return local_u8ReceivedData;
}



void MUART_voidSetCallBack (UART_INTERRUPTS_e A_InterruptSource , void (*A_PtoFunc)(void))
{
	if ((A_InterruptSource<=UART_TX_INTERRUPT)&&(A_PtoFunc != NULL))
	{
		FuncPtr [A_InterruptSource] = A_PtoFunc;
	}
}


void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if (FuncPtr[UART_RX_INTERRUPT] != NULL)
	{
		FuncPtr[UART_RX_INTERRUPT]();
	}
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	if (FuncPtr[UART_UDRE_INTERRUPT] != NULL)
	{
		FuncPtr[UART_UDRE_INTERRUPT]();
	}
}

void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	if (FuncPtr[UART_TX_INTERRUPT] != NULL)
	{
		FuncPtr[UART_TX_INTERRUPT]();
	}
}
