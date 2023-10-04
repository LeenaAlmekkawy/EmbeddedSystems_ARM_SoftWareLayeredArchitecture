/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: HAL               *********/
/*********  SWC: TFT                 *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SPI/SPI_interface.h"
#include "../../MCAL/STK/STK_interface.h"


#include "TFT_config.h"
#include "TFT_interface.h"
#include "TFT_private.h"
static u16 Global_u16CurrentXPosStart;
static u16 Global_u16CurrentXPosEnd;

static u16 Global_u16CurrentYPosStart;
static u16 Global_u16CurrentYPosEnd;

void HTFT_voidWriteCmd(u16 Copy_u16Cmd)
{
	GPIO_voidSetPinValue(TFT_A0_PORT,TFT_A0_PIN,LOW);
	(void)MSPI1_u16Transceive(Copy_u16Cmd);

}

void HTFT_voidWriteData(u16 Copy_u16Data)
{
	GPIO_voidSetPinValue(TFT_A0_PORT,TFT_A0_PIN,HIGH);
	(void)MSPI1_u16Transceive(Copy_u16Data);
}

void HTFT_voidResetSequence(void)
{
	GPIO_voidSetPinValue(TFT_RST_PORT,TFT_RST_PIN,HIGH);

	MSTK_voidSetBusyWait(200);
	GPIO_voidSetPinValue(TFT_RST_PORT,TFT_RST_PIN,LOW);

	MSTK_voidSetBusyWait(4);
	GPIO_voidSetPinValue(TFT_RST_PORT,TFT_RST_PIN,HIGH);

	MSTK_voidSetBusyWait(200);
	GPIO_voidSetPinValue(TFT_RST_PORT,TFT_RST_PIN,LOW);

	MSTK_voidSetBusyWait(200);
	GPIO_voidSetPinValue(TFT_RST_PORT,TFT_RST_PIN,HIGH);

	MSTK_voidSetBusyWait(240000);

}

void HTFT_voidInit(void)
{   //1- SET Pin directions
	PIN_st TFT={OUTPUT,PP,VHS,NPP};
	GPIO_voidSetPinDirection ( TFT_A0_PORT,TFT_A0_PIN,&TFT);

	GPIO_voidSetPinDirection ( TFT_RST_PORT,TFT_RST_PIN,&TFT);

	MSPI1_voidInit();

	//2- reset sequence
	HTFT_voidResetSequence();

	//3- send sleep out command (0x11)
	HTFT_voidWriteCmd(0x11);

	//4- wait 15ms
	//MSTK_voidSetTime_ms_2MHZ(30000);
	MSTK_voidSetBusyWait(30000);

	//5- send color mode command ->RGB565 (0x3A)& argument (0x05)
	HTFT_voidWriteCmd(0x3A);
	HTFT_voidWriteData(0X05);

	//6- Display on command(0x29)
	HTFT_voidWriteCmd(0x29);


}

void HTFT_voidShowImage(u16 Copy_pu16Img[],u32 Copy_u32ImgSize)
{
	//1- set x position
	HTFT_voidWriteCmd(0x2A);
	//X start=0 , x end=127
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(127);


	//2- set Y position
	HTFT_voidWriteCmd(0x2B);
	//y start=0 , x end=159
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(159);

	//3- send image data
	HTFT_voidWriteCmd(0x2C);

	u32 Local_counter;
	for(Local_counter=0;Local_counter< Copy_u32ImgSize;Local_counter++)
	{
		HTFT_voidWriteData( (Copy_pu16Img[Local_counter]>>8) ); //MSB byte
		HTFT_voidWriteData( (Copy_pu16Img[Local_counter] & 0x00FF) );  //LSB Byte
	}



}

void HTFT_voidSetXPos(u16 Copy_u16xStart, u16 Copy_u16xEnd)
{
	Global_u16CurrentXPosStart=Copy_u16xStart;
	Global_u16CurrentXPosEnd=Copy_u16xEnd;

	HTFT_voidWriteCmd(0x2A);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(Copy_u16xStart);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(Copy_u16xEnd);




}

void HTFT_voidSetYPos(u16 Copy_u16yStart, u16 Copy_u16yEnd)
{
	Global_u16CurrentYPosStart=Copy_u16yStart;
	Global_u16CurrentYPosEnd=Copy_u16yEnd;

	HTFT_voidWriteCmd(0x2B);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(Copy_u16yStart);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(Copy_u16yEnd);
}

void HTFT_voidFillRectangle(Color_t Copy_u16Color)
{
	HTFT_voidWriteCmd(0x2C);

	u32 Local_u32NumOfPixels=(Global_u16CurrentYPosEnd - Global_u16CurrentYPosStart)*(Global_u16CurrentXPosEnd - Global_u16CurrentXPosStart);

	u32 Local_counter;
	for(Local_counter=0;Local_counter< Local_u32NumOfPixels;Local_counter++)
	{
		HTFT_voidWriteData( Copy_u16Color.color>>8); //MSB byte
		HTFT_voidWriteData( Copy_u16Color.color & 0x00FF );  //LSB Byte
	}

}

void HTFT_voidFillBackGround(Color_t Copy_u16Color)
{
	HTFT_voidWriteCmd(0x2A);
	//X start=0 , x end=127
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(127);


	//2- set Y position
	HTFT_voidWriteCmd(0x2B);
	//y start=0 , y end=159
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(159);
	Global_u16CurrentYPosStart=0;
	Global_u16CurrentYPosEnd=159;
	Global_u16CurrentXPosStart=0;
	Global_u16CurrentXPosEnd=127;


	HTFT_voidFillRectangle(Copy_u16Color);

}
