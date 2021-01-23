/**************************************************************************************/
/*    Author  : OsamaMahmoud                                                          */
/*    Date    : 13/8/2020                                                             */
/*    Version : V01                                                                   */
/**************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
//#include "DIO_config.h"

void DIO_voidSetDirection(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8mode)
{
	switch(Copy_u8port)
	{
		case GPIOA : 
		if(Copy_u8pin<=7)
		{
			GPIOA_CRL &= ~((0b1111)<<(Copy_u8pin*4));
			GPIOA_CRL |=  ((Copy_u8mode)<<(Copy_u8pin*4));
		}
		else if(Copy_u8pin<=15)
		{
			Copy_u8pin = Copy_u8pin-8;
			GPIOA_CRH &= ~((0b1111)<<(Copy_u8pin*4));
			GPIOA_CRH |=  ((Copy_u8mode)<<(Copy_u8pin*4));
			
		}
		break;
		case GPIOB : 
		if(Copy_u8pin<=7)
		{
			GPIOB_CRL &= ~((0b1111)<<(Copy_u8pin*4));
			GPIOB_CRL |=  ((Copy_u8mode)<<(Copy_u8pin*4));
		}
		else if(Copy_u8pin<=15)
		{
			Copy_u8pin = Copy_u8pin-8;
			GPIOB_CRH &= ~((0b1111)<<(Copy_u8pin*4));
			GPIOB_CRH |=  ((Copy_u8mode)<<(Copy_u8pin*4));
			
		}
		break;
		case GPIOC : 
		if(Copy_u8pin<=7)
		{
			GPIOC_CRL &= ~((0b1111)<<(Copy_u8pin*4));
			GPIOC_CRL |=  ((Copy_u8mode)<<(Copy_u8pin*4));
		}
		else if(Copy_u8pin<=15)
		{
			Copy_u8pin = Copy_u8pin-8;
			GPIOC_CRH &= ~((0b1111)<<(Copy_u8pin*4));
			GPIOC_CRH |=  ((Copy_u8mode)<<(Copy_u8pin*4));
			
		}
		break;
	}
}
void DIO_voidSetValue(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8value)
{
	switch(Copy_u8port)
	{
		case GPIOA : 
		if(Copy_u8value == GPIO_HIGH)
		{
			//SET_BIT(GPIOA_ODR, Copy_u8pin); 
			GPIOA_BSRR = (1<<Copy_u8pin);
		}
		else if(Copy_u8value == GPIO_LOW)
		{
			CLR_BIT(GPIOA_ODR, Copy_u8pin);
			GPIOA_BRR = (1<<Copy_u8pin);
		}
		break;
		case GPIOB : 
		if(Copy_u8value == GPIO_HIGH)
		{
			//SET_BIT(GPIOB_ODR, Copy_u8pin); 
			GPIOB_BSRR = (1<<Copy_u8pin);
		}
		else if(Copy_u8value == GPIO_LOW)
		{
			//CLR_BIT(GPIOB_ODR, Copy_u8pin);
			GPIOB_BRR = (1<<Copy_u8pin);
		}
		break;
		case GPIOC : 
		if(Copy_u8value == GPIO_HIGH)
		{
			//SET_BIT(GPIOC_ODR, Copy_u8pin); 
			GPIOC_BSRR = (1<<Copy_u8pin);
		}
		else if(Copy_u8value == GPIO_LOW)
		{
			//CLR_BIT(GPIOC_ODR, Copy_u8pin);
			GPIOC_BRR = (1<<Copy_u8pin);
		}
		break;
	}
}
u8 DIO_u8GetValue(u8 Copy_u8port,u8 Copy_u8pin)
{   
    u8 Value=0;
	switch(Copy_u8port)
	{
		case GPIOA : 
		Value = GET_BIT(GPIOA_IDR, Copy_u8pin);
		break;
		case GPIOB : 
		Value = GET_BIT(GPIOB_IDR, Copy_u8pin);
		break;
		case GPIOC : 
		Value = GET_BIT(GPIOC_IDR, Copy_u8pin);
		break;
	}
	return Value;
}
void DIO_voidTogPin(u8 Copy_u8port, u8 Copy_u8pin)
{
		switch(Copy_u8port)
	{
		case GPIOA : 
		TOG_BIT(GPIOA_ODR, Copy_u8pin);
		break;
		case GPIOB : 
		TOG_BIT(GPIOB_ODR, Copy_u8pin);
		break;
		case GPIOC : 
		TOG_BIT(GPIOC_ODR, Copy_u8pin);
		break;
	}
}
void DIO_voidSetLockPin(u8 Copy_u8port, u8 Copy_u8bit)
{
	switch(Copy_u8port)
	{
		case GPIOA :
		if(Copy_u8bit<=15)
		{
			SET_BIT(GPIOA_LCKR,Copy_u8bit);  // each bit freezes 4 bits of(CRL,CRH)
		}
		case GPIOB :
		if(Copy_u8bit<=15)
		{
			SET_BIT(GPIOB_LCKR,Copy_u8bit);
		}
		case GPIOC :
		if(Copy_u8bit<=15)
		{
			SET_BIT(GPIOC_LCKR,Copy_u8bit);
		}
	}
}
void DIO_voidSetPort(u8 Copy_u8port, u8 Copy_u8value)
{
   switch(Copy_u8port)
   {
         case GPIOA :
         SET_PORT(GPIOA_ODR,Copy_u8value);
         break;
         case GPIOB :
         SET_PORT(GPIOB_ODR,Copy_u8value);
         break;
         case GPIOC :
         SET_PORT(GPIOC_ODR,Copy_u8value);
         break;
   }
}
void DIO_voidWritePins(u8 Copy_u8Port,u8 Copy_u8StartPin,u8 Copy_u8NumberofPins,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIOA :
		GPIOA_ODR &= ~(Copy_u8NumberofPins<<Copy_u8StartPin);
		GPIOA_ODR |=  (Copy_u8Value       <<Copy_u8StartPin);
		break;
		case GPIOB :
		GPIOB_ODR &= ~(Copy_u8NumberofPins<<Copy_u8StartPin);
		GPIOB_ODR |=  (Copy_u8Value       <<Copy_u8StartPin);
		break;
		case GPIOC :
		GPIOC_ODR &= ~(Copy_u8NumberofPins<<Copy_u8StartPin);
		GPIOC_ODR |=  (Copy_u8Value       <<Copy_u8StartPin);
		break;
		default : break;
	}
}