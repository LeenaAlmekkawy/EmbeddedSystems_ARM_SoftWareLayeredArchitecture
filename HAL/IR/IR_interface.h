/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: HAL               *********/
/*********  SWC: IR                  *********/
/*********  Version: 1.00            *********/
/*********************************************/
/*********************************************/
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H


void HIR_voidInit(void);

u8 HIR_u8GetButtonID(void);

void HIR_GetFrame(void);

void HIR_ParseFrame(void);

#define IR_B1               69
#define IR_B2               70
#define IR_B3               71
#define IR_B4               68
#define IR_B5               64
#define IR_B6               67
#define IR_B7               7
#define IR_B8               21
#define IR_B9               9
#define IR_B10              22
#define IR_B11              25
#define IR_B12              13
#define IR_B13              12
#define IR_B14              24
#define IR_B15              94
#define IR_B16              8
#define IR_B17              28
#define IR_B18              90
#define IR_B19              66
#define IR_B20              82
#define IR_B21              74

#endif
