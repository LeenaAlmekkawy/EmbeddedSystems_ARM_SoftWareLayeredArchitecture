/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: HAL               *********/
/*********  SWC: DAC                 *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/
#ifndef DAC_INTERFACE_H
#define DAC_INTERFACE_H

void HDAC_voidInit(void);

void HDAC_voidWriteData(u8 copy_u8Data);

void HDAC_voidSendSound(u8* Copy_pu8SoundArray,u32 Copy_u32ArraySize);

void HDAC_voidDACISR(void);

void HDAC_voidPlaySound(void);
#endif
