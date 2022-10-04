/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: MCAL              *********/
/*********  SWC: EXTI                *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

enum
{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15

};


#define DISABLE    0
#define ENABLE     1


#define RISING_EDGE  1
#define FALLING_EDGE 2
#define ON_CHANGE    3




void MEXTI_voidInit(void);

void MEXTI_voidEnableLine(u8 Copy_u8Trigger ,u8 Copy_u8LineNum);

void MEXTI_voidDisableLine(u8 Copy_u8LineNum);

void MEXTI_voidSoftwareTrigger(u8 Copy_u8LineNum);

void MEXTI_voidSetTrigger(u8 Copy_u8Trigger ,u8 Copy_u8LineNum);

void MEXTI_voidSetCallBack(u8 Copy_u8LineNum ,void (*Copy_pvNotificationFunction)(void));

       
#endif
