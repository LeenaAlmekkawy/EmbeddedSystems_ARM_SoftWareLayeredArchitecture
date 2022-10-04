/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: MCAL              *********/
/*********  SWC: EXTI                *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"

static void (*Global_pvEXTI_LINE0_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE1_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE2_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE3_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE4_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE5_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE6_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE7_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE8_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE9_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE10_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE11_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE12_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE13_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE14_CallBack)(void)=NULL;
static void (*Global_pvEXTI_LINE15_CallBack)(void)=NULL;

void MEXTI_voidInit(void)
{
 EXTI->PR=0XFFFFFFFF;
 EXTI->IMR=0;
 EXTI->IMR|=((EXTI_LINE_0_EN <<0)   | (EXTI_LINE_1_EN <<1)   |
		    (EXTI_LINE_2_EN <<2)   | (EXTI_LINE_3_EN <<3)   |
		    (EXTI_LINE_4_EN <<4)   | (EXTI_LINE_5_EN <<5)   |
		    (EXTI_LINE_6_EN <<6)   | (EXTI_LINE_7_EN <<7)   |
		    (EXTI_LINE_8_EN <<8)   | (EXTI_LINE_9_EN <<9)   |
		    (EXTI_LINE_10_EN <<10) | (EXTI_LINE_11_EN <<11) |
		    (EXTI_LINE_12_EN <<12) | (EXTI_LINE_13_EN <<13) |
		    (EXTI_LINE_14_EN <<14) | (EXTI_LINE_15_EN <<15) );

#if     EXTI_LINE_0_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,0);
#elif   EXTI_LINE_0_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,0);
#elif   EXTI_LINE_0_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,0);
    SET_BIT(EXTI->FTSR,0);
#endif

#if     EXTI_LINE_1_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,1);
#elif   EXTI_LINE_1_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,1);
#elif   EXTI_LINE_1_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,1);
    SET_BIT(EXTI->FTSR,1);
#endif

#if     EXTI_LINE_2_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,2);
#elif   EXTI_LINE_2_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,2);
#elif   EXTI_LINE_2_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,2);
    SET_BIT(EXTI->FTSR,2);
#endif

#if     EXTI_LINE_3_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,3);
#elif   EXTI_LINE_3_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,3);
#elif   EXTI_LINE_3_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,3);
    SET_BIT(EXTI->FTSR,3);
#endif

#if     EXTI_LINE_4_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,4);
#elif   EXTI_LINE_4_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,4);
#elif   EXTI_LINE_4_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,4);
    SET_BIT(EXTI->FTSR,4);
#endif

#if     EXTI_LINE_5_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,5);
#elif   EXTI_LINE_5_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,5);
#elif   EXTI_LINE_5_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,5);
    SET_BIT(EXTI->FTSR,5);
#endif

#if     EXTI_LINE_6_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,6);
#elif   EXTI_LINE_6_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,6);
#elif   EXTI_LINE_6_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,6);
    SET_BIT(EXTI->FTSR,6);
#endif

#if     EXTI_LINE_7_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,7);
#elif   EXTI_LINE_7_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,7);
#elif   EXTI_LINE_7_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,7);
    SET_BIT(EXTI->FTSR,7);
#endif

#if     EXTI_LINE_8_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,8);
#elif   EXTI_LINE_8_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,8);
#elif   EXTI_LINE_8_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,8);
    SET_BIT(EXTI->FTSR,8);
#endif

#if     EXTI_LINE_9_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,9);
#elif   EXTI_LINE_9_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,9);
#elif   EXTI_LINE_9_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,9);
    SET_BIT(EXTI->FTSR,9);
#endif

#if     EXTI_LINE_10_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,10);
#elif   EXTI_LINE_10_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,10);
#elif   EXTI_LINE_10_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,10);
    SET_BIT(EXTI->FTSR,10);
#endif

#if     EXTI_LINE_11_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,11);
#elif   EXTI_LINE_11_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,11);
#elif   EXTI_LINE_11_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,11);
    SET_BIT(EXTI->FTSR,11);
#endif

#if     EXTI_LINE_12_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,12);
#elif   EXTI_LINE_12_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,12);
#elif   EXTI_LINE_12_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,12);
    SET_BIT(EXTI->FTSR,12);
#endif

#if     EXTI_LINE_13_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,13);
#elif   EXTI_LINE_13_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,13);
#elif   EXTI_LINE_13_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,13);
    SET_BIT(EXTI->FTSR,13);
#endif

#if     EXTI_LINE_14_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,14);
#elif   EXTI_LINE_14_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,14);
#elif   EXTI_LINE_14_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,14);
    SET_BIT(EXTI->FTSR,14);
#endif

#if     EXTI_LINE_15_TRIGGER==RISING_EDGE
    SET_BIT(EXTI->RTSR,15);
#elif   EXTI_LINE_15_TRIGGER==FALLING_EDGE
    SET_BIT(EXTI->FTSR,15);
#elif   EXTI_LINE_15_TRIGGER==ON_CHANGE
    SET_BIT(EXTI->RTSR,15);
    SET_BIT(EXTI->FTSR,15);
#endif





}

void MEXTI_voidEnableLine(u8 Copy_u8Trigger ,u8 Copy_u8LineNum)
{
	if(Copy_u8LineNum<16)
	{
		  SET_BIT(EXTI->IMR, Copy_u8LineNum);

		  switch(Copy_u8Trigger)
		  {
		  case RISING_EDGE:
			  SET_BIT(EXTI->RTSR,Copy_u8LineNum);
			  CLR_BIT(EXTI->FTSR,Copy_u8LineNum);
			  break;
		  case FALLING_EDGE:
			  SET_BIT(EXTI->FTSR,Copy_u8LineNum);
			  CLR_BIT(EXTI->RTSR,Copy_u8LineNum);
			  break;
		  case ON_CHANGE:
			  SET_BIT(EXTI->RTSR,Copy_u8LineNum);
			  SET_BIT(EXTI->FTSR,Copy_u8LineNum);
			  break;
		  }
	}

}

void MEXTI_voidDisableLine(u8 Copy_u8LineNum)
{
	if(Copy_u8LineNum<16)
		{
			  CLR_BIT(EXTI->IMR, Copy_u8LineNum);
		}

}

void MEXTI_voidSoftwareTrigger(u8 Copy_u8LineNum)
{
	if(Copy_u8LineNum<16)
		{
			 SET_BIT(EXTI->SWIER, Copy_u8LineNum);
		}
}

void MEXTI_voidSetTrigger(u8 Copy_u8Trigger ,u8 Copy_u8LineNum)
{
	if(Copy_u8LineNum<16)
		{

			  switch(Copy_u8Trigger)
			  {
			  case RISING_EDGE:
				  SET_BIT(EXTI->RTSR,Copy_u8LineNum);
				  CLR_BIT(EXTI->FTSR,Copy_u8LineNum);
				  break;
			  case FALLING_EDGE:
				  SET_BIT(EXTI->FTSR,Copy_u8LineNum);
				  CLR_BIT(EXTI->RTSR,Copy_u8LineNum);
				  break;
			  case ON_CHANGE:
				  SET_BIT(EXTI->RTSR,Copy_u8LineNum);
				  SET_BIT(EXTI->FTSR,Copy_u8LineNum);
				  break;
			  }
		}
}

void MEXTI_voidSetCallBack(u8 Copy_u8LineNum ,void (*Copy_pvNotificationFunction)(void))
{
	switch(Copy_u8LineNum)
	{
	case EXTI_LINE0:
		Global_pvEXTI_LINE0_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE1:
		Global_pvEXTI_LINE1_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE2:
		Global_pvEXTI_LINE2_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE3:
		Global_pvEXTI_LINE3_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE4:
		Global_pvEXTI_LINE4_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE5:
		Global_pvEXTI_LINE5_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE6:
		Global_pvEXTI_LINE6_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE7:
		Global_pvEXTI_LINE7_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE8:
		Global_pvEXTI_LINE8_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE9:
		Global_pvEXTI_LINE9_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE10:
		Global_pvEXTI_LINE10_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE11:
		Global_pvEXTI_LINE11_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE12:
		Global_pvEXTI_LINE12_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE13:
		Global_pvEXTI_LINE13_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE14:
		Global_pvEXTI_LINE14_CallBack=Copy_pvNotificationFunction;
		break;

	case EXTI_LINE15:
		Global_pvEXTI_LINE15_CallBack=Copy_pvNotificationFunction;
		break;

	}
}


void  EXTI0_IRQHandler(void)
{

    if(Global_pvEXTI_LINE0_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE0_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE0);
}

void  EXTI1_IRQHandler(void)
{
    if(Global_pvEXTI_LINE1_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE1_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE1);

}

void  EXTI2_IRQHandler(void)
{
    if(Global_pvEXTI_LINE2_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE2_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE2);

}

void  EXTI3_IRQHandler(void)
{
    if(Global_pvEXTI_LINE3_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE3_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE3);

}

void  EXTI4_IRQHandler(void)
{
    if(Global_pvEXTI_LINE4_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE4_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE4);

}

void  EXTI5_IRQHandler(void)
{
    if(Global_pvEXTI_LINE5_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE5_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE5);

}

void  EXTI6_IRQHandler(void)
{
    if(Global_pvEXTI_LINE6_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE6_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE6);

}

void  EXTI7_IRQHandler(void)
{
    if(Global_pvEXTI_LINE7_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE7_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE7);

}

void  EXTI8_IRQHandler(void)
{
    if(Global_pvEXTI_LINE8_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE8_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE8);

}

void  EXTI9_IRQHandler(void)
{
    if(Global_pvEXTI_LINE9_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE9_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE9);

}

void  EXTI10_IRQHandler(void)
{
    if(Global_pvEXTI_LINE10_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE10_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE10);

}

void  EXTI11_IRQHandler(void)
{
    if(Global_pvEXTI_LINE11_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE11_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE11);

}


void  EXTI12_IRQHandler(void)
{
    if(Global_pvEXTI_LINE12_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE12_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE12);

}

void  EXTI13_IRQHandler(void)
{
    if(Global_pvEXTI_LINE13_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE13_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE13);

}

void  EXTI14_IRQHandler(void)
{
    if(Global_pvEXTI_LINE14_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE14_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE14);

}

void  EXTI15_IRQHandler(void)
{
    if(Global_pvEXTI_LINE15_CallBack!=NULL)
    {
    	Global_pvEXTI_LINE15_CallBack();
    }
    SET_BIT(EXTI->PR,EXTI_LINE15);

}



