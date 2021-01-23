/***************************************************************************************/
/* Author : OsamaMahmoud                                                               */
/* Date   : 13/8/2020                                                                  */
/***************************************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "DIO_interface.h"

void LED_ON(u8 port,u8 pin);
void LED_OFF(u8 port,u8 pin);
void LED_TOG(u8 port,u8 pin);




#endif