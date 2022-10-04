/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: MCAL              *********/
/*********  SWC: NVIC                *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADD   (u32)(0xE000E100)
#define SCB_BASE_ADD    (u32)(0xE000ED00)

typedef struct
{
	u32  ISER[32];
	u32  ICER[32];
	u32  ISPR[32];
	u32  ICPR[32];
	u32  IABR[32];
	u32  Reserved[32];
	u8   IPR[240];



}NVIC_MemMap_t;

#define NVIC      ((volatile NVIC_MemMap_t*)(NVIC_BASE_ADD))


typedef struct
{

	u32 CPUID;
	u32 ICSR;
	u32 VTOR;
	u32 AIRCR;
	u32 SCR;
	u32 CCR;
	u32 SHPR1;
	u32 SHPR2;
	u32 SHPR3;
	u32 SHCSR;
	u32 CFSR;
	u32 MMSR;
	u32 BFSR;
	u32 UFSR;
	u32 HFSR;
	u32 MMAR;
	u32 BFAR;
	u32 AFSR;

}SCB_MemMap_t;

#define SCB ((volatile SCB_MemMap_t*)(SCB_BASE_ADD))

#endif
