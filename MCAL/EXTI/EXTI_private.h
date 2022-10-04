/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: MCAL              *********/
/*********  SWC: EXTI                *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_BASE_ADD   (u32)(0x40013C00)

typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;

}EXTI_MemMap_t;

#define EXTI      ((volatile EXTI_MemMap_t* )(EXTI_BASE_ADD))

#define NULL    (void *)0




#endif
