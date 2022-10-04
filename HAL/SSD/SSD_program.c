#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

void SSD_voidInit(SSD_st* Copy_pstSSDInfo)
{
	PIN_st SSD={OUTPUT,PP,HS,NPP};
	GPIO_voidSetPinDirection (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN0 ,&SSD);
	GPIO_voidSetPinDirection (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN1 ,&SSD);
	GPIO_voidSetPinDirection (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN2 ,&SSD);
	GPIO_voidSetPinDirection (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN3 ,&SSD);
	GPIO_voidSetPinDirection (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN4 ,&SSD);
	//GPIO_voidSetPinDirection (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN5 ,&SSD);
	//GPIO_voidSetPinDirection (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN6 ,&SSD);
	//GPIO_voidSetPinDirection (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN7 ,&SSD);
	GPIO_voidSetPinDirection (PORTA,Copy_pstSSDInfo->SSD_PIN5 ,&SSD);
    GPIO_voidSetPinDirection (PORTA,Copy_pstSSDInfo->SSD_PIN6 ,&SSD);
}
void SSD_voidSetNumber(u8 Copy_u8Number, SSD_st* Copy_pstSSDInfo) {

	u32 Localu32_NumbersArray[10] = { ZERO, ONE, TWO, THREE, FOUR, FIVE,
	SIX, SEVEN, EIGHT, NINE };

	if (Copy_u8Number >= MINIMUM_ALLOWED_NUMBER && Copy_u8Number <= MAXIMUN_ALLOWED_NUMBER) {
		if (Copy_pstSSDInfo->SSD_ComType == COMMON_ANODE) {


			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN0 ,GET_BIT(~Localu32_NumbersArray[Copy_u8Number],0));
			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN1 ,GET_BIT(~Localu32_NumbersArray[Copy_u8Number],1));
			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN2 ,GET_BIT(~Localu32_NumbersArray[Copy_u8Number],2));
			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN3 ,GET_BIT(~Localu32_NumbersArray[Copy_u8Number],3));
			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN4 ,GET_BIT(~Localu32_NumbersArray[Copy_u8Number],4));
		//	GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN5 ,GET_BIT(~Localu32_NumbersArray[Copy_u8Number],5));
			//GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN6 ,GET_BIT(~Localu32_NumbersArray[Copy_u8Number],6));
			//GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN7 ,GET_BIT(~Localu32_NumbersArray[Copy_u8Number],7));
			GPIO_voidSetPinValue (PORTA,Copy_pstSSDInfo->SSD_PIN5 ,GET_BIT(~Localu32_NumbersArray[Copy_u8Number],5));
			GPIO_voidSetPinValue (PORTA,Copy_pstSSDInfo->SSD_PIN6 ,GET_BIT(~Localu32_NumbersArray[Copy_u8Number],6));
		}
		else if (Copy_pstSSDInfo->SSD_ComType == COMMON_CATHODE) {

			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN0 ,GET_BIT(Localu32_NumbersArray[Copy_u8Number],0));
			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN1 ,GET_BIT(Localu32_NumbersArray[Copy_u8Number],1));
			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN2 ,GET_BIT(Localu32_NumbersArray[Copy_u8Number],2));
			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN3 ,GET_BIT(Localu32_NumbersArray[Copy_u8Number],3));
			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN4 ,GET_BIT(Localu32_NumbersArray[Copy_u8Number],4));
			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN5 ,GET_BIT(Localu32_NumbersArray[Copy_u8Number],5));
			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN6 ,GET_BIT(Localu32_NumbersArray[Copy_u8Number],6));
			GPIO_voidSetPinValue (Copy_pstSSDInfo->SSD_PORT,Copy_pstSSDInfo->SSD_PIN7 ,GET_BIT(Localu32_NumbersArray[Copy_u8Number],7));
		}
	}

}

