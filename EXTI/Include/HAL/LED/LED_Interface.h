/*
 * LED_Interface.h
 *
 *  Created on: Sep 9, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_LED_LED_INTERFACE_H_
#define INCLUDE_HAL_LED_LED_INTERFACE_H_

void HLED_voidTurnLEDOn(DIO_PORT_e A_portID, DIO_PIN_e A_pinID);
void HLED_voidTurnLEDOff(DIO_PORT_e A_portID, DIO_PIN_e A_pinID);
void HLED_voidToggleLED(DIO_PORT_e A_portID, DIO_PIN_e A_pinID);


#endif /* INCLUDE_HAL_LED_LED_INTERFACE_H_ */
