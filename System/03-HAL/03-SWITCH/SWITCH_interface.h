/***********************************************************************************************/
/*  Author   :  OsamaMahmoud                                                                   */
/*  Date     :  23/8/2020                                                                      */
/*  Version  :  V01                                                                            */
/***********************************************************************************************/
#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "DIO_interface.h"

/* Copy_u8mode Options : INPUT_FLOATING*/
void SWITCH_voidInit(u8 Copy_u8Port,u8 Copy_u8Pin);

/* Copy_u8INTERNAL Options : PULLUP
                             PULLDOWN               */

void SWITCH_voidSetPP_PD(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8INTERNAL);

u8 SWITCH_u8GetState(u8 Copy_u8Port,u8 Copy_u8Pin);







#endif