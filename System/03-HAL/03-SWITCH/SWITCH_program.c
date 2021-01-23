/***********************************************************************************************/
/*  Author   :  OsamaMahmoud                                                                   */
/*  Date     :  23/8/2020                                                                      */
/*  Version  :  V01                                                                            */
/***********************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SWITCH_interface.h"
#include "SWITCH_private.h"
#include "SWITCH_config.h"


void SWITCH_voidInit(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case GPIOA :
		DIO_voidSetDirection(GPIOA,Copy_u8Pin,INPUT_FLOATING);
		break;
		
		case GPIOB:
		DIO_voidSetDirection(GPIOB,Copy_u8Pin,INPUT_FLOATING);
		break;
		
		case GPIOC:
		DIO_voidSetDirection(GPIOC,Copy_u8Pin,INPUT_FLOATING);
		break;
	}
}
void SWITCH_voidSetPP_PD(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8INTERNAL)
{
	switch(Copy_u8Port)
	{
		case GPIOA :
		if(Copy_u8INTERNAL == SWITCH_PULLUP)
		{
			DIO_voidSetDirection(GPIOA,Copy_u8Pin,INPUT_PP_PD);
			DIO_voidSetValue(GPIOA,Copy_u8Pin,GPIO_HIGH);
		}
		else if(Copy_u8INTERNAL == SWITCH_PULLDOWN)
		{
            DIO_voidSetDirection(GPIOA,Copy_u8Pin,INPUT_PP_PD);
			DIO_voidSetValue(GPIOA,Copy_u8Pin,GPIO_LOW);
		}
		break;
		
		case GPIOB :
		if(Copy_u8INTERNAL == SWITCH_PULLUP)
		{
			DIO_voidSetDirection(GPIOA,Copy_u8Pin,INPUT_PP_PD);
			DIO_voidSetValue(GPIOB,Copy_u8Pin,GPIO_HIGH);
		}
		else if(Copy_u8INTERNAL == SWITCH_PULLDOWN)
		{
            DIO_voidSetDirection(GPIOB,Copy_u8Pin,INPUT_PP_PD);
			DIO_voidSetValue(GPIOB,Copy_u8Pin,GPIO_LOW);
		}
		break;
		
		case GPIOC :
		if(Copy_u8INTERNAL == SWITCH_PULLUP)
		{
			DIO_voidSetDirection(GPIOC,Copy_u8Pin,INPUT_PP_PD);
			DIO_voidSetValue(GPIOC,Copy_u8Pin,GPIO_HIGH);
		}
		else if(Copy_u8INTERNAL == SWITCH_PULLDOWN)
		{
            DIO_voidSetDirection(GPIOC,Copy_u8Pin,INPUT_PP_PD);
			DIO_voidSetValue(GPIOC,Copy_u8Pin,GPIO_LOW);
		}
		break;
	}
}

u8 SWITCH_u8GetState(u8 Copy_u8Port,u8 Copy_u8Pin)
{   u8 Local_u8Value=0;
	switch(Copy_u8Port)
	{
		case GPIOA :
		Local_u8Value = DIO_u8GetValue(Copy_u8Port,Copy_u8Pin);
		break;
		
		case GPIOB :
		Local_u8Value = DIO_u8GetValue(Copy_u8Port,Copy_u8Pin);
		break;
		
		case GPIOC :
		Local_u8Value = DIO_u8GetValue(Copy_u8Port,Copy_u8Pin);
		break;
		
		return Local_u8Value;
		
	}
}