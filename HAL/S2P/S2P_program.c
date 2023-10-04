/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: HAL               *********/
/*********  SWC: S2P                 *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "S2P_config.h"
#include "S2P_interface.h"
#include "S2P_private.h"

static void ShiftData(void)
{
	GPIO_voidSetPinValue(S2P_PORT, S2P_SHIFT_PIN,HIGH);
	MSTK_voidSetTime_us_2MHZ(1);
	GPIO_voidSetPinValue(S2P_PORT, S2P_SHIFT_PIN, LOW);
}

static void LatchData(void)
{
	GPIO_voidSetPinValue(S2P_PORT,S2P_LATCH_PIN,HIGH);
	MSTK_voidSetTime_us_2MHZ(1);
	GPIO_voidSetPinValue(S2P_PORT, S2P_LATCH_PIN, LOW);
}

void HS2P_voidInit(void)
{
	PIN_st PinOut= {OUTPUT,PP,VHS,NPP};

	GPIO_voidSetPinDirection (S2P_PORT, S2P_SHIFT_PIN, &PinOut);
	GPIO_voidSetPinDirection (S2P_PORT, S2P_LATCH_PIN, &PinOut);
	GPIO_voidSetPinDirection (S2P_PORT, S2P_DATA_PIN , &PinOut);


}

void HS2P_voidSendData(u32 Copy_u32Data)
{
	//put data on data pin

	//shift data using shift pin
	/* 1- send high
	 * 2- delay
	 * 3- send law
	 */

	for(u32 Local_u8Counter=0 ; Local_u8Counter<DATA_SIZE*S2P_NUM_OF_REGS  ; Local_u8Counter++)
	{
		u8 Local_u8DataBit=GET_BIT(Copy_u32Data,Local_u8Counter);
		GPIO_voidSetPinValue(S2P_PORT, S2P_DATA_PIN, Local_u8DataBit);
		ShiftData();


	}

	//send a latch signal for the output
	/* 1- send high
	 * 2- delay
	 * 3- send law
	 */

	 LatchData();






}
