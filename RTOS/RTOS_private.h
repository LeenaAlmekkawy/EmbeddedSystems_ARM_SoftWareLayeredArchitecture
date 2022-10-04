/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: MCAL              *********/
/*********  SWC: RTOS                *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/

#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

#define Suspended                  0
#define Running                    1

typedef struct
{
	void (*TaskHandler)(void) ;
	u8   Periodicity;
	u8   FirstDelay;
	/*
	 * 1-Suspended
	 * 2-Running
	 */
	u8   TaskRunState;

}Task;

#endif
