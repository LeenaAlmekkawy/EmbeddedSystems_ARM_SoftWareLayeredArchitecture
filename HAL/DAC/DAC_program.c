/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: HAL               *********/
/*********  SWC: DAC                 *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "DAC_config.h"
#include "DAC_interface.h"
#include "DAC_private.h"


u8 Global_u8SoundArray[60000];
u32 Global_u32ArraySize;
u8 Global_u8Flag=0;

void HDAC_voidInit(void)
{
	PIN_st DAC_st={OUTPUT,PP,HS,NPP};
	GPIO_voidSetPinDirection(DAC_PORT ,DAC_PIN0 ,&DAC_st);
	GPIO_voidSetPinDirection(DAC_PORT ,DAC_PIN1 ,&DAC_st);
	GPIO_voidSetPinDirection(DAC_PORT ,DAC_PIN2 ,&DAC_st);
	GPIO_voidSetPinDirection(DAC_PORT ,DAC_PIN3 ,&DAC_st);
	GPIO_voidSetPinDirection(DAC_PORT ,DAC_PIN4 ,&DAC_st);
	GPIO_voidSetPinDirection(DAC_PORT ,DAC_PIN5 ,&DAC_st);
	GPIO_voidSetPinDirection(DAC_PORT ,DAC_PIN6 ,&DAC_st);
	GPIO_voidSetPinDirection(DAC_PORT ,DAC_PIN7 ,&DAC_st);

}

void HDAC_voidWriteData(u8 copy_u8Data)
{
	GPIO_voidSetPinValue ( DAC_PORT, DAC_PIN0 , GET_BIT(copy_u8Data,DAC_Bit0) );
	GPIO_voidSetPinValue ( DAC_PORT, DAC_PIN1 , GET_BIT(copy_u8Data,DAC_Bit1) );
	GPIO_voidSetPinValue ( DAC_PORT, DAC_PIN2 , GET_BIT(copy_u8Data,DAC_Bit2) );
	GPIO_voidSetPinValue ( DAC_PORT, DAC_PIN3 , GET_BIT(copy_u8Data,DAC_Bit3) );
	GPIO_voidSetPinValue ( DAC_PORT, DAC_PIN4 , GET_BIT(copy_u8Data,DAC_Bit4) );
	GPIO_voidSetPinValue ( DAC_PORT, DAC_PIN5 , GET_BIT(copy_u8Data,DAC_Bit5) );
	GPIO_voidSetPinValue ( DAC_PORT, DAC_PIN6 , GET_BIT(copy_u8Data,DAC_Bit6) );
	GPIO_voidSetPinValue ( DAC_PORT, DAC_PIN7 , GET_BIT(copy_u8Data,DAC_Bit7) );


}

void HDAC_voidSendSound(u8* Copy_pu8SoundArray,u32 Copy_u32ArraySize)
{
	u32 Local_u32Counter;
	for( Local_u32Counter=0; Local_u32Counter<Copy_u32ArraySize ;Local_u32Counter++)
	{
		 Global_u8SoundArray[Local_u32Counter]=Copy_pu8SoundArray[Local_u32Counter];
	}

	Global_u32ArraySize=Copy_u32ArraySize;



}
void HDAC_voidDACISR(void)
{

	      static u32 Local_u32Counter=0;

			HDAC_voidWriteData(Global_u8SoundArray[Local_u32Counter]);

			if(Local_u32Counter <Global_u32ArraySize-3)
				{

				Local_u32Counter++;

				}
				else
				{
				Local_u32Counter = 0 ;
				 MSTK_voidStopTimer();

				}




}
void HDAC_voidPlaySound(void)
{
	MSTK_voidStartTimer();

//	MSTK_voidSetIntervalSingle(250,HDAC_voidDACISR);
	MSTK_voidSetIntervalPeriodic(250,HDAC_voidDACISR);

}

