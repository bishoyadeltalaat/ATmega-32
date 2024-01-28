/*
 * WDT_Interface.h
 *
 *  Created on: Oct 20, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_WDT_WDT_INTERFACE_H_
#define INCLUDE_MCAL_WDT_WDT_INTERFACE_H_

/*
	0 --> 0 0 0  16.3ms
	1 --> 0 0 1  32.5ms
	2 --> 0 1 0  65ms
	3 --> 0 1 1  0.13 s
	4 --> 1 0 0  0.26s
	5 --> 1 0 1  0.52s
	6 --> 1 1 0  1.0s
	7 --> 1 1 1  2.1s
 */
typedef enum{
	WDT_16_3_ms=0,
	WDT_32_5_ms,
	WDT_65_ms,
	WDT_0_13_s,
	WDT_0_25_s,
	WDT_0_52_s,
	WDT_1_0_s,
	WDT_2_1_s
}WDT_TIME_e;

void MWDT_voidEnable(WDT_TIME_e A_TimeToReset);
void MWDT_voidDisable(void);

#endif /* INCLUDE_MCAL_WDT_WDT_INTERFACE_H_ */
