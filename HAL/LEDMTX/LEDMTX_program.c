#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "../S2P/S2P_interface.h"

#include "LEDMTX_private.h"
#include "LEDMTX_config.h"
#include "LEDMTX_interface.h"


u8 Global_u8ColumnsArray[8]={COLS_PIN0 ,COLS_PIN1 ,COLS_PIN2 ,COLS_PIN3 ,COLS_PIN4 ,COLS_PIN5 ,COLS_PIN6 ,COLS_PIN7 };
u8 Global_u8RowsArray[8]={ROWS_PIN0,ROWS_PIN1,ROWS_PIN2,ROWS_PIN3,ROWS_PIN4,ROWS_PIN5,ROWS_PIN6,ROWS_PIN7};

#if LEDMTX_METHODE==DIRECT
static void HLEDMTX_voidDisableAllColumns(void)
{
	for(u8 Local_u8Counter=0; Local_u8Counter<NO_COLS ;Local_u8Counter++ )
	{
		GPIO_voidSetPinValue (COLS_PORT, Global_u8ColumnsArray[Local_u8Counter] , HIGH);

	}

}

static void  HLEDMTX_voidSetRowValues(u8 Copy_u8RowValues)
{
	for(u8 Local_u8Counter=0; Local_u8Counter<NO_COLS ;Local_u8Counter++ )
	{
		GPIO_voidSetPinValue (ROWS_PORT, Global_u8RowsArray[Local_u8Counter] , (GET_BIT(Copy_u8RowValues,Local_u8Counter)));

	}
}

static void	 HLEDMTX_voidSetCurrentColumn(u8 Copy_u8colNum)
{
	GPIO_voidSetPinValue (COLS_PORT, Global_u8ColumnsArray[Copy_u8colNum], LOW);
}
#endif

void HLEDMTX_voidInit(void)
{
#if LEDMTX_METHODE==DIRECT

	PIN_st PinOut= {OUTPUT,PP,VHS,NPP};
	for(u8 Local_u8Counter=0; Local_u8Counter<NO_COLS ;Local_u8Counter++ )
	{
		GPIO_voidSetPinDirection (COLS_PORT, Global_u8ColumnsArray[Local_u8Counter] , &PinOut);

	}

	for(u8 Local_u8Counter=0; Local_u8Counter<NO_ROWS ;Local_u8Counter++ )
	{
		GPIO_voidSetPinDirection (ROWS_PORT, Global_u8RowsArray[Local_u8Counter] , &PinOut);

	}
#elif  LEDMTX_METHODE==S2P
	HS2P_voidInit();

#endif




}

void HLEDMTX_voidDisplayFrame(u8 Frame[],u32 Copy_u32FrameDelay)
{
#if LEDMTX_METHODE==S2P
  u16 Local_u16S2pData=0;
#endif

	u32 Local_u32Delay= Copy_u32FrameDelay/20;
	for(u32 Local_u32DelayCounter=0; Local_u32DelayCounter<Local_u32Delay; Local_u32DelayCounter++)
	{
		for(u8 Local_u8Counter=0; Local_u8Counter<NO_COLS ;Local_u8Counter++ )
		{
#if LEDMTX_METHODE==DIRECT

			//Disable all columns
			HLEDMTX_voidDisableAllColumns();
			//set row values
			HLEDMTX_voidSetRowValues(Frame[Local_u8Counter]);

			//set current column
			HLEDMTX_voidSetCurrentColumn(Local_u8Counter);

#elif LEDMTX_METHODE==S2P
			//Disable all columns
			 Local_u16S2pData=DISABLE_ALL_COLS;
			 HS2P_voidSendData( Local_u16S2pData);
			//set row values
			 Local_u16S2pData=( Frame[Local_u8Counter] );

			//set current column
			 Local_u16S2pData|= ( (~(1<<Local_u8Counter)) <<8  )  ;
					 HS2P_voidSendData(Local_u16S2pData);
#endif
			//delay for suitable  frame per second(2.5 ms)
			MSTK_voidSetTime_ms_2MHZ(SCAN_TIME);

		}
	}

}

void HLEDMTX_voidDisplayMatrix(u8 Matrix[][NO_COLS], u32 Copy_u32NumOfFrames,u32 Copy_u32MatrixDelay)
{

	for(u32 Local_u32Counter=0; Local_u32Counter<Copy_u32NumOfFrames;Local_u32Counter++)
	{
		HLEDMTX_voidDisplayFrame(Matrix[Local_u32Counter],Copy_u32MatrixDelay);
	}

}



