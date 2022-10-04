/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: MCAL              *********/
/*********  SWC: RTOS                *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/

#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

u8 RTOS_u8CreateTask( void(*Copy_Handler)(void)  , u8 Copy_u8periodicity , u8 Copy_u8Priority,u8 Copy_u8FirstDelay );

void RTOS_voidScheduler(void);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);


void RTOS_voidDeleteTask(u8 Copy_u8Priority);

void RTOS_voidResumeTask(u8 Copy_u8Priority);

void RTOS_voidStartOS(void);

#endif
