/**************************************************************************************/
/*  Author    : OsamaMahmoud                                                          */
/*  Date      : 14/8/2020                                                             */
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SEVEN_SEG_interface.h"
#include "SEVEN_SEG_config.h"
#include "SEVEN_SEG_private.h"


void Seg_Init(u8 Port,u8 Pin)
{
	switch(Port)
	{
		case GPIOA :
		DIO_voidSetDirection(GPIOA,Pin,OUTPUT_PP_10MHZ);
		break;
		case GPIOB :
		DIO_voidSetDirection(GPIOB,Pin,OUTPUT_PP_10MHZ);
		break;
		case GPIOC :
		DIO_voidSetDirection(GPIOC,Pin,OUTPUT_PP_10MHZ);
		break;
		default :
		break;
	}
}
void Display(u8 Port,u8 Num)
{
	DIO_voidSetPort(Port,data[Num]);
}