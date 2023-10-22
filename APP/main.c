#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/RCC/RCC_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/STK/STK_interface.h"
#include "../MCAL/USART/USART_interface.h"

int main(void)
{
	MRCC_voidSystemClkInit();
	MSTK_voidInit();
	MRCC_voidEnablePerClk(RCC_AHB1,RCC_EN_GPIOA);
	PIN_st PinOut={OUTPUT,PP,LS,NPP};
	GPIO_voidSetPinDirection(GPIO_PORTA,PIN0,& PinOut);

	MRCC_voidEnablePerClk(RCC_APB2,RCC_EN_USART1);

	  PIN_st USART_PinAF= {AF,PP,HS,NPP};
	   GPIO_voidSetPinDirection (GPIO_PORTA ,PIN10, &USART_PinAF);
	   GPIO_voidSetPinDirection (GPIO_PORTA ,PIN9, &USART_PinAF);

	   GPIO_voidSetAlternativeFunction(GPIO_PORTA ,PIN10, GPIO_AF_7);
	   GPIO_voidSetAlternativeFunction(GPIO_PORTA ,PIN9,  GPIO_AF_7);





	USART_InitType uart={9600,MODE_8BIT,STOP_BIT_1,DISABLE,EVEN_PARITY,TX_RX,DISABLE,OVER_SAMPLING_16};
	USART_ClockInitType uartclock ={DISABLE,0,0,0};
		// Initialization of USART1
		MUSART_voidInit(&uart, &uartclock, USART1);

		// Enable USART1
	//	MUSART_voidEnable(USART1);
	//	GPIO_voidSetPinValue(GPIO_PORTA,PIN0,HIGH);
		//GPIO_voidSetPinValue(GPIO_PORTA,PIN0,HIGH);
	//	MUSART_voidTransmitByte(USART1,'A');


	    while(1)
		  {
	    	MUSART_voidTransmitByte(USART1,'A');
       MSTK_voidSetTime_ms_2MHZ(200);
       GPIO_voidSetPinValue(GPIO_PORTA,PIN0,HIGH);



        }
}









/*#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/RCC/RCC_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/STK/STK_interface.h"
//#include "../MCAL/SPI/SPI_interface.h"
#include "../HAL/TFT/TFT_interface.h"
#include "TFT_Img.h"

void main(void)
{

	MRCC_voidSystemClkInit();
	//enable clock for PORTA &PORTB&PORTC
	MRCC_voidEnablePerClk(RCC_AHB1, RCC_EN_GPIOA);
	MRCC_voidEnablePerClk(RCC_AHB1, RCC_EN_GPIOB);
	MRCC_voidEnablePerClk(RCC_AHB1, RCC_EN_GPIOC);
	MRCC_voidEnablePerClk(RCC_APB2, RCC_EN_SPI1);
	////enable SYSCFG
//	MRCC_voidEnablePerClk(RCC_APB2,RCC_EN_SYSCFG);
	MSTK_voidInit();

	PIN_st PinOut= {OUTPUT,PP,VHS,NPP};
	//  PIN_st PinIN= {INPUT,PP,VHS,NPP};


	//-------------------
	 HTFT_voidInit();
		HTFT_voidShowImage(IMG,20480);
	/* Color_t bg;
	 bg.pixel.Blu=0b11111;
	 bg.pixel.Grn=0;
	 bg.pixel.Red=0;

 //  HTFT_voidFillBackGround(bg);

/*	HTFT_voidSetXPos(20,20+30);
	HTFT_voidSetXPos(20,20+60);
	 Color_t reg;
	 reg.pixel.Blu=0;
	 reg.pixel.Grn=0b111111;
	 reg.pixel.Red=0;
	HTFT_voidFillRectangle(reg);






	while(1)
	{


	}
}*/
