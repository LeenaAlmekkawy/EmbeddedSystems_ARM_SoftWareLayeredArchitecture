
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/RCC/RCC_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/NVIC/NVIC_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/SYSCFG/SYSCFG_interface.h"
#include "../MCAL/STK/STK_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/LEDMTX/LEDMTX_interface.h"
#include "../HAL/S2P/S2P_interface.h"
#include "../RTOS/RTOS_interface.h"
/*
 * forbidden pins :-
 * PORTA:13,14,15
 * PORTB:2,3,4
 *
 *
 */


void main(void)
{    u8 smile[]={255, 129, 129, 129, 129, 129, 129, 255};
    u8 face[]={52, 52, 52, 48, 48, 52, 52, 52};
u8 E[]={0, 0, 254, 146, 146, 146, 0, 0};
u8 Test[]={0, 126, 64, 64, 64, 64, 64, 0};
u8 new[]={0, 0, 0, 0, 0, 0, 0, 0};
u8 matrix[2][8]={{52, 82, 148, 144, 144, 148, 82, 52}
,{52, 52, 52, 48, 48, 52, 52, 52}};

	 MRCC_voidSystemClkInit();
	 //enable clock for PORTA &PORTB&PORTC
	 MRCC_voidEnablePerClk(RCC_AHB1, RCC_EN_GPIOA);
	 MRCC_voidEnablePerClk(RCC_AHB1, RCC_EN_GPIOB);
	 MRCC_voidEnablePerClk(RCC_AHB1, RCC_EN_GPIOC);

	  MSTK_voidInit();
     HLEDMTX_voidInit();
    //  HS2P_voidInit();




 	//HLEDMTX_voidDisplayFrame(smile,1000);


	    while(1)
	    {
	    HLEDMTX_voidDisplayMatrix( matrix, 2,2000);




	    }
}
