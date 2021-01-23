/*****************************************************************/
/* Author  : OsamaMahmoud                                        */
/* Date    : 12/10/2020                                          */
/*****************************************************************/
#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H


void FPEC_voidFlashWrite(u32 Copy_u32Address , u16 *Copy_u16Data , u8 Copy_u8Length);
void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber);
void FPEC_voidMassErase(void);













#endif