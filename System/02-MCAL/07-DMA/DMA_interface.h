/**************************************************************************************/
/*  Author  : OsamaMahmoud                                                            */
/*  Date    : 14/9/2020                                                               */
/**************************************************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H



void DMA_voidInitChannel(void);

void DMA_voidStartChannel(u32 *Copy_Pu32SourceAdrress,u32 *Copy_Pu32DestinationAdrress,u16 Copy_u16BlockLength);









#endif