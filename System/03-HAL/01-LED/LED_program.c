/***************************************************************************************/
/* Author : OsamaMahmoud                                                               */
/* Date   : 13/8/2020                                                                  */
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
/*#include "LED_private.h"
#include "LED_config.h"*/

void LED_ON(u8 port,u8 pin)
{
   switch(port)
   {
	   case GPIOA : DIO_voidSetValue(GPIOA,pin,GPIO_HIGH); break;
	   
	   case GPIOB : DIO_voidSetValue(GPIOB,pin,GPIO_HIGH); break;
	   
	   case GPIOC : DIO_voidSetValue(GPIOC,pin,GPIO_HIGH); break;
	   
   }	   
}
void LED_OFF(u8 port,u8 pin)
{
	switch(port)
   {
	   case GPIOA : DIO_voidSetValue(GPIOA,pin,GPIO_LOW); break;
	   
	   case GPIOB : DIO_voidSetValue(GPIOB,pin,GPIO_LOW); break;
	   
	   case GPIOC : DIO_voidSetValue(GPIOC,pin,GPIO_LOW); break;
	   
   }	   
}
void LED_TOG(u8 port,u8 pin)
{
	switch(port)
   {
	   case GPIOA : DIO_voidTogPin(GPIOA,pin); break;
	   
	   case GPIOB : DIO_voidTogPin(GPIOB,pin); break;
	   
	   case GPIOC : DIO_voidTogPin(GPIOC,pin); break;
	   
   }	   
}