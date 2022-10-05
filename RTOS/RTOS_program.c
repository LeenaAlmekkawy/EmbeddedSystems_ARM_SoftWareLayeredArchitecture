/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: MCAL              *********/
/*********  SWC: RTOS                *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/STK/STK_interface.h"

#include "RTOS_private.h"
#include "RTOS_interface.h"
#include "RTOS_config.h"


Task SystemTasks[MAX_NUM_OF_TASKS]={0};
u32  Systemperiodicity[MAX_NUM_OF_TASKS]={0};
u32 TaskTiming[MAX_NUM_OF_TASKS];
Task Empty= {0};

void RTOS_voidStartOS(void)
{
	MSTK_voidSetIntervalPeriodic(TickTime,RTOS_voidScheduler);
	while(1){}
}


void RTOS_u8CreateTask( void(*Copy_Handler)(void)  , u32 Copy_u32periodicity , u8 Copy_u8Priority,u32 Copy_u32FirstDelay )
{

	//verify that the priority index within the correct range
	if(Copy_u8Priority < MAX_NUM_OF_TASKS)
	{
		if(SystemTasks[Copy_u8Priority].TaskHandler==0)
		{
			SystemTasks[Copy_u8Priority].TaskHandler= Copy_Handler;
			SystemTasks[Copy_u8Priority].Periodicity= Copy_u32periodicity ;
			SystemTasks[Copy_u8Priority].TaskRunState= Running;
			Systemperiodicity[Copy_u8Priority]=Copy_u32periodicity;
			TaskTiming[Copy_u8Priority]= Copy_u32FirstDelay;
		}
		else
		{
			//The required priority is already reserved

		}
	}
	else
	{
		//wrong priority

	}

}

void RTOS_voidScheduler(void)
{
	u8 Local_u8Counter=0;
	//loop on all tasks
	for(Local_u8Counter=0;Local_u8Counter<MAX_NUM_OF_TASKS; Local_u8Counter++)
	{
		//Is there a registered task?
		if(SystemTasks[Local_u8Counter].TaskHandler!=0)
		{
			if(SystemTasks[Local_u8Counter].TaskRunState== Running)
			{

				if(TaskTiming[Local_u8Counter]==0)
				{
                      //run the task
					 SystemTasks[Local_u8Counter].TaskHandler();
					 //Reload the periodicity
					 TaskTiming[Local_u8Counter]=Systemperiodicity[Local_u8Counter];

				}
				else
				{
					 TaskTiming[Local_u8Counter]--;
				}
			}
		}
	}
}

void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{

	if(SystemTasks[Copy_u8Priority].TaskHandler !=0)
	{
		SystemTasks[Copy_u8Priority].TaskRunState=Suspended;
	}
	else
	{
		//Task not exist
	}

}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{

	if(SystemTasks[Copy_u8Priority].TaskHandler !=0)
	{
		SystemTasks[Copy_u8Priority]=Empty;
	}
	else
	{
		//Task not exist
	}

}

void RTOS_voidResumeTask(u8 Copy_u8Priority)
{

	if(SystemTasks[Copy_u8Priority].TaskHandler !=0)
	{
		SystemTasks[Copy_u8Priority].TaskRunState=Running;
	}
	else
	{
		//Task not exist
	}

}



