
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/RCC/RCC_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/NVIC/NVIC_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/SYSCFG/SYSCFG_interface.h"
#include "../MCAL/STK/STK_interface.h"
#include "../RTOS/RTOS_interface.h"
/*
 * forbidden pins :-
 * PORTA:13,14,15
 * PORTB:2,3,4
 *
 *
 */
u8 f0=0;
void LED0ON(void)
{
          if(f0==0)
          {
        	   GPIO_voidSetPinValue     (PORTA, PIN0, LOW);
        	   f0=1;
          }
          else if(f0==1)
          {   GPIO_voidSetPinValue     (PORTA, PIN0, HIGH);
              f0=0;

          }




}
u8 f1=0;
void LED1ON(void)
{
          if(f1==0)
          {
        	   GPIO_voidSetPinValue     (PORTA, PIN1, LOW);
        	   f1=1;
          }
          else if(f1==1)
          {   GPIO_voidSetPinValue     (PORTA, PIN1, HIGH);
              f1=0;

          }




}

u8 f2=0;
void LED2ON(void)
{
          if(f2==0)
          {
        	   GPIO_voidSetPinValue     (PORTA, PIN2, LOW);
        	   f2=1;
          }
          else if(f2==1)
          {   GPIO_voidSetPinValue     (PORTA, PIN2, HIGH);
              f2=0;

          }




}

u8 f3=0;
void LED3ON(void)
{
          if(f3==0)
          {
        	   GPIO_voidSetPinValue     (PORTA, PIN3, LOW);
        	   f3=1;
          }
          else if(f3==1)
          {   GPIO_voidSetPinValue     (PORTA, PIN3, HIGH);
              f3=0;

          }




}

u8 f4=0;
void LED4ON(void)
{
          if(f4==0)
          {
        	   GPIO_voidSetPinValue     (PORTA, PIN4, LOW);
        	   f4=1;
          }
          else if(f4==1)
          {   GPIO_voidSetPinValue     (PORTA, PIN4, HIGH);
              f4=0;

          }




}

u8 f5=0;
void LED5ON(void)
{
          if(f5==0)
          {
        	   GPIO_voidSetPinValue     (PORTA, PIN5, LOW);
        	   f5=1;
          }
          else if(f5==1)
          {   GPIO_voidSetPinValue     (PORTA, PIN5, HIGH);
              f5=0;

          }




}
u8 f6=0;
void LED6ON(void)
{
          if(f6==0)
          {
        	   GPIO_voidSetPinValue     (PORTA, PIN6, LOW);
        	   f6=1;
          }
          else if(f6==1)
          {   GPIO_voidSetPinValue     (PORTA, PIN6, HIGH);
              f6=0;

          }




}
u8 f7=0;
void LED7ON(void)
{
          if(f7==0)
          {
        	   GPIO_voidSetPinValue     (PORTA, PIN7, LOW);
        	   f7=1;
          }
          else if(f7==1)
          {   GPIO_voidSetPinValue     (PORTA, PIN7, HIGH);
              f7=0;

          }




}



void main(void)
{

    MRCC_voidSystemClkInit();
    //enable clock for PORTA &PORTB&PORTC
    MRCC_voidEnablePerClk(RCC_AHB1, RCC_EN_GPIOA);
    MRCC_voidEnablePerClk(RCC_AHB1, RCC_EN_GPIOB);
    MRCC_voidEnablePerClk(RCC_AHB1, RCC_EN_GPIOC);
    MRCC_voidEnablePerClk(RCC_APB2,RCC_EN_SYSCFG);

    MSTK_voidInit();
    PIN_st PinOut = {OUTPUT,PP,VHS,NPP};
    for(u8 i=0;i<8;i++)
    GPIO_voidSetPinDirection (PORTA, i, &PinOut );


     RTOS_u8CreateTask( LED0ON,50, 0,1 );
     RTOS_u8CreateTask( LED1ON,150, 1,1 );
     RTOS_u8CreateTask( LED2ON,200, 2,1 );
     RTOS_u8CreateTask( LED3ON,250, 3,1 );
     RTOS_u8CreateTask( LED4ON,300, 4,1 );
     RTOS_u8CreateTask( LED5ON,350, 5,1 );
     RTOS_u8CreateTask( LED6ON,400, 6,1 );
     RTOS_u8CreateTask( LED7ON,450, 7,1 );
   // RTOS_u8CreateTask( LED1OFF, 1000, 2,500 );

      RTOS_voidStartOS();
    //  MSTK_voidSetIntervalPeriodic(2000000, LED1);
   // MSTK_voidSetIntervalSingle(200000,LED1 );

    while(1)
    {




    }
}
