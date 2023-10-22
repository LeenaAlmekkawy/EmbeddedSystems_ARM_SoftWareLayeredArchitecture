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

void RTOS_u8CreateTask( void(*Copy_Handler)(void)  , u32 Copy_u8periodicity , u8 Copy_u8Priority,u32 Copy_u32FirstDelay );

void RTOS_voidScheduler(void);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);

void RTOS_voidDeleteTask(u8 Copy_u8Priority);

void RTOS_voidResumeTask(u8 Copy_u8Priority);

void RTOS_voidStartOS(void);

#endif
