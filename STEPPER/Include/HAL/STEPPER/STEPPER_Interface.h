/*
 * STEPPER_Interface.h
 *
 *  Created on: Nov 5, 2023
 *      Author: D E L L
 */

#ifndef INCLUDE_HAL_STEPPER_STEPPER_INTERFACE_H_
#define INCLUDE_HAL_STEPPER_STEPPER_INTERFACE_H_

void HSTEPPER_voidInit(void);
void HSTEPPER_voidRotate(u16 A_u16Angle);
void HSTEPPER_voidCounterRotate(u16 A_u16Angle);

#endif /* INCLUDE_HAL_STEPPER_STEPPER_INTERFACE_H_ */
