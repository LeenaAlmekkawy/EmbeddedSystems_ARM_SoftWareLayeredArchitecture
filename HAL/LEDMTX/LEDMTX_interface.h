/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: HAL               *********/
/*********  SWC: LEDMTX              *********/
/*********  Version: 1.1             *********/
/*********************************************/
/*********************************************/
#ifndef LEDMTX_INTERFACE_H
#define LEDMTX_INTERFACE_H



#define NO_COLS               8
#define S2P                   0
#define DIRECT                1


void HLEDMTX_voidInit(void);

void HLEDMTX_voidDisplayFrame(u8 Frame[],u32 Copy_u32FrameDelay);

void HLEDMTX_voidDisplayMatrix(u8 Matrix[][NO_COLS], u32 Copy_u32NumOfFrames,u32 Copy_u32MatrixDelay);




#endif
