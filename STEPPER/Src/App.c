/*
 * App.c
 *
 *  Created on: Nov 2, 2023
 *      Author: D E L L
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/HAL/STEPPER/STEPPER_Interface.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Cfg.h"

#define F_CPU 8000000UL


int main(void){

	HSTEPPER_voidInit();
	while(1){
		HSTEPPER_voidRotate(180);
		HSTEPPER_voidCounterRotate(180);
	}
}
