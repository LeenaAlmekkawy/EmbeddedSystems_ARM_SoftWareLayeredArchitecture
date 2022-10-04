/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: MCAL              *********/
/*********  SWC: NVIC                *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
//Group options
#define GROUP_4BITS     0b011
#define GROUP_3BITS     0b100
#define GROUP_2BITS     0b101
#define GROUP_1BITS     0b110
#define GROUP_0BITS     0b111

#define MEMORY_MANAGEMENT -3
#define BUS_FAULT         -2
#define USAGE_FAULT       -1

#define SV_CALL           -4

#define PEND_SV           -6
#define SYSTICK           -5

#define WWDG 0
#define EXTI16 1
#define EXTI21 2
#define EXTI22 3
#define FLASH 4
#define RCC 5
#define EXTI0 6
#define EXTI1 7
#define EXTI2 8
#define EXTI3 9
#define EXTI4 10
#define DMA1_STREAM0 11
#define DMA1_STREAM1 12
#define DMA1_STREAM2 13
#define DMA1_STREAM3 14
#define DMA1_STREAM4 15
#define DMA1_STREAM5 16
#define DMA1_STREAM6 17
#define ADC 18
#define EXTI9 23
#define TIM1_BRK_TIM9 24
#define TIM1_UP_TIM10 25
#define TIM1_TRG_COM_TIM11 26
#define TIM1_CC 27
#define TIM2 28
#define TIM3 29
#define TIM4 30
#define I2C1_EV 31
#define I2C1_ER 32
#define I2C2_EV 33
#define I2C2_ER 34
#define SPI1 35
#define SPI2 36
#define USART1 37
#define USART2 38
#define EXTI15_10 30
#define EXTI17 41
#define EXTI18 42
#define DMA1_STREAM7 47
#define SDIO 49
#define TIM5 50
#define SPI3 51
#define DMA2_STREAM0 56
#define DMA2_STREAM1 57
#define DMA2_STREAM2 58
#define DMA2_STREAM3 59
#define DMA2_STREAM4 60
#define OTG_FS 67
#define DMA2_STREAM5 68
#define DMA2_STREAM6 69
#define DMA2_STREAM7 70
#define USART6 71
#define I2C3_EV 72
#define I2C3_ER 73
#define FPU 81
#define SPI4 84




void MNVIC_voidEnablePeripheral(u8 copy_u8InterruptID);

void MNVIC_voidDisablePeripheral(u8 copy_u8InterruptID);

void MNVIC_voidSetPending(u8 copy_u8InterruptID);

void MNVIC_voidClearPending(u8 copy_u8InterruptID);

u8 MNVIC_u8GetActive(u8 Copy_u8InterruptID);

void MNVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption);

void MNVIC_voidSetPriority (s8 Copy_s8InterruptID,u8 Copy_u8GroupPriority, u8 Copy_u8SubGroupPriority);

       
#endif
