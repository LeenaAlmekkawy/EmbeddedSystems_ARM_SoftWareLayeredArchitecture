/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: HAL               *********/
/*********  SWC: IR                  *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "IR_config.h"
#include "IR_interface.h"
#include "IR_private.h"

u8 Global_u8StartFalg=0;
u32 FrameData[50];
u32 EdgeCounter =0 ;
u8 IR_Data=0;

void HIR_voidInit(void)
{
    PIN_st IRPinIN= {INPUT,PP,VHS,PU};
    GPIO_voidSetPinDirection (IR_PORT, IR_PIN , &IRPinIN);
}

u8 HIR_u8GetButtonID(void)
{
	   MEXTI_voidSetCallBack(IR_EXTI_LINE , HIR_GetFrame);
	   return IR_Data;

}

void HIR_GetFrame(void)
{
  if(Global_u8StartFalg == 0)
   {
	   MSTK_voidSetIntervalSingle(IR_NO_TICKS,HIR_ParseFrame);
	   Global_u8StartFalg=1;
   }
   else
   {
	   FrameData[EdgeCounter]= MSTK_u32GetElapsedTime();
	   MSTK_voidSetIntervalSingle(IR_NO_TICKS,  HIR_ParseFrame);
	   EdgeCounter++;

   }

}

void HIR_ParseFrame(void)
{

  u8 Local_u8Counter;
  for(Local_u8Counter=0;Local_u8Counter<IR_NO_DATA_BITS ;Local_u8Counter++)
  {
	  if(FrameData[17+Local_u8Counter]>=4000 &&FrameData[17+Local_u8Counter]<=5000)
	  {
		  SET_BIT(IR_Data,Local_u8Counter);
	  }
	  else
	  {
		  CLR_BIT(IR_Data,Local_u8Counter);
	  }
  }
  Global_u8StartFalg=0;
  EdgeCounter =0 ;

}

