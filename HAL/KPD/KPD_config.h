/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: HAL               *********/
/*********  SWC: KPD                 *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/
#ifndef KBD_CONFIG_H
#define KBD_CONFIG_H

#define KPD_COLUMNS_PORT  GPIO_PORTB
#define KPD_COLUMN0_PIN   PIN0
#define KPD_COLUMN1_PIN   PIN1
#define KPD_COLUMN2_PIN   PIN2
#define KPD_COLUMN3_PIN   PIN5

#define KPD_ROWS_PORT  GPIO_PORTB

#define KPD_ROW0_PIN PIN6
#define KPD_ROW1_PIN PIN7
#define KPD_ROW2_PIN PIN8
#define KPD_ROW3_PIN PIN9

#define KPD_KEYSARRAY_VALUES {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}}

#define KPD_NO_PRESSEDKEY  0xAAAAAAAA


#endif
