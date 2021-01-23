/**********************************************************/
/* Author  : Osama Mahmoud                                */
/* Date    : 9/4/2020                                     */
/**********************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_private.h"


typedef enum 
{
	LOW =0,
	HIGH=1,
}Voltage_Type;

typedef enum
{
	PA = 0,
	PB,
	PC,
}Port_Type;

extern void DIO_Init(void);
extern void DIO_WritePin(PinNum_type Pin,Voltage_Type Value);
extern Voltage_Type DIO_ReadPin( PinNum_type Pin);
extern void DIO_WritePort(Port_Type Port,u8 Value);





#endif