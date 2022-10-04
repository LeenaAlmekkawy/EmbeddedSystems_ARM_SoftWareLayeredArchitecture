/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: MCAL              *********/
/*********  SWC: NVIC                *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "NVIC_private.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"

static u32 GlobalStatic_u32GroupConf;

void MNVIC_voidEnablePeripheral(u8 Copy_u8InterruptID)
{
	NVIC->ISER[Copy_u8InterruptID/32]=( 1<<(Copy_u8InterruptID%32) );
}

void MNVIC_voidDisablePeripheral(u8 Copy_u8InterruptID)
{
	NVIC->ICER[Copy_u8InterruptID/32]=( 1<<(Copy_u8InterruptID%32) );
}

void MNVIC_voidSetPending(u8 Copy_u8InterruptID)
{
	NVIC->ISPR[Copy_u8InterruptID/32]=( 1<<(Copy_u8InterruptID%32) );
}

void MNVIC_voidClearPending(u8 Copy_u8InterruptID)
{
	NVIC->ICPR[Copy_u8InterruptID/32]=( 1<<(Copy_u8InterruptID%32) );
}

u8 MNVIC_u8GetActive(u8 Copy_u8InterruptID)
{
  u8 Local_u8GetActiveValue=0;
  Local_u8GetActiveValue=GET_BIT( (NVIC->IABR[Copy_u8InterruptID/32]), (Copy_u8InterruptID%32)   );
  return Local_u8GetActiveValue;

}

void MNVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption)
{
	GlobalStatic_u32GroupConf= (0x5FA0000|(Copy_u8PriorityOption<<8) );
	SCB->AIRCR=GlobalStatic_u32GroupConf;
}

void MNVIC_voidSetPriority (s8 Copy_s8InterruptID,u8 Copy_u8GroupPriority, u8 Copy_u8SubGroupPriority)
{
   /*
    * if    |  shift Group by
    * 0b011 |    0
    * 0b100 |    1
    * 0b101 |    2
    * 0b110 |    3
    * 0b111 |    4
    *
    */
	u8 Local_u8Priority = Copy_u8SubGroupPriority | Copy_u8GroupPriority << ((GlobalStatic_u32GroupConf- 0x05FA0300) / 256);

   //core peripheralS
	if(Copy_s8InterruptID<0)
	{
       if(Copy_s8InterruptID==MEMORY_MANAGEMENT  || Copy_s8InterruptID==BUS_FAULT ||Copy_s8InterruptID==USAGE_FAULT)
       {
    	   Copy_s8InterruptID+=3;
    	   u32 Local_u32Mask=0x0000000F;
    	   SCB->SHPR1&=(~(Local_u32Mask<<((8*Copy_s8InterruptID)+4)));

    	   SCB->SHPR1|=(Local_u8Priority)<<((8*Copy_s8InterruptID)+4);
       }
       else if(Copy_s8InterruptID==SV_CALL)
       {
    	   Copy_s8InterruptID+=7;
       	   u32 Local_u32Mask=0x0000000F;
           SCB->SHPR2&=(~(Local_u32Mask<<((8*Copy_s8InterruptID)+4)));
    	   SCB->SHPR2|=( (Local_u8Priority)<<((8*Copy_s8InterruptID)+4));
       }
       else if(Copy_s8InterruptID==PEND_SV   || Copy_s8InterruptID==SYSTICK)
       {
    	   Copy_s8InterruptID+=8;
       	   u32 Local_u32Mask=0x0000000F;
           SCB->SHPR3&=(~(Local_u32Mask<<((8*Copy_s8InterruptID)+4)));
    	   SCB->SHPR3|=((Local_u8Priority)<<((8*Copy_s8InterruptID)+4));
       }
	}
	//external peripheralS
	else if(Copy_s8InterruptID>=0)
	{
		NVIC->IPR[Copy_s8InterruptID]=(Local_u8Priority<<4);
	}

}


