/****************************************************************************************/
/* Author :  OsamaMahmoud                                                               */
/* Date   :  16/9/2020                                                                  */
/****************************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


void SPI1_voidInit(void);
void SPI1_voidSendReceiveSynch(u16 Copy_u16DataToTransmit , u16 *Copy_DataToReceive);
void SPI1_voidSendReceiveAsynch(u16 Copy_u16DataToTransmit , void (*CallBack)(u16));
void SPI1_voidInitMaster(void);
void SPI1_voidInitSlave(void);










#endif  