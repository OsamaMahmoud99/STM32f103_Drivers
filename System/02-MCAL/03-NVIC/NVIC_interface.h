/*****************************************************************************************/
/* Author    :   Osama Mahmoud                                                           */
/* Date      :   20/8/2020                                                               */
/* Version   :   V01                                                                     */
/*****************************************************************************************/
#ifndef  NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


void MNVIC_voidInit(void);
void MNVIC_voidSetPriority(u8 Copy_PeripheralIdx, u8 Copy_u8Priority);
void NVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void NVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void NVIC_voidSetInterruptPending(u8 Copy_u8IntNumber);
void NVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);


#define GROUP3       0x05FA0300  // 4 bits for group
#define GROUP4       0x05FA0400  // 3 bits for group and 1 bit  for sub
#define GROUP5       0x05FA0500  // 2 bits for group and 2 bits for sub
#define GROUP6       0x05FA0600
#define GROUP7       0x05FA0700










#endif